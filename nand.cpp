#define _CRT_SECURE_NO_WARNINGS
//----------------------------------------------------------
//
// A Simple Page-mapping FTL Simulator
//
// Feb. 2, 2017
//
// Jin-Soo Kim (jinsookim@skku.edu)
// Computer Systems Laboratory
// Sungkyunkwan University
// http://csl.skku.edu
//
//----------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "nand.h"

using namespace std;


#define SSD_SHIFT	          	32
#define PAGE_SHIFT	           	12
#define PAGES_PER_BLOCK_SHIFT	7
#define OP_RATIO				15
#define N_RUNS                  10

#define PPN_SHIFT				(SSD_SHIFT - PAGE_SHIFT)
#define BLOCKS_SHIFT			(PPN_SHIFT - PAGES_PER_BLOCK_SHIFT)

#define N_PAGE_SIZE				(1 << PAGE_SHIFT)
#define N_PAGES_PER_BLOCK		(1 << PAGES_PER_BLOCK_SHIFT)
#define N_PPNS					(1 << PPN_SHIFT)
#define N_BLOCKS				(1 << BLOCKS_SHIFT)
#define N_USER_BLOCKS           (N_BLOCKS * 100 / (100 + OP_RATIO))
#define N_OP_BLOCKS				(N_BLOCKS - N_USER_BLOCKS)
#define N_LPNS					(N_USER_BLOCKS * N_PAGES_PER_BLOCK)
#define LPN_COUNTS				(N_LPNS * N_RUNS)

#define invalid -1000

struct pm_stat {
	int gc;
	long host_write;
	long gc_write;
} s;


//logical page -> physical page
int L2PPagemap[N_LPNS + 1];

//physical page -> logical page
int P2LPagemap[N_PPNS + 1];

//spare block number 단 하나 밖에 없다.
int spareBlockNumber;

//블락의 invalid한 page의 개수를 저장
int inValidNumInBlock[N_BLOCKS + 1];

//지금 비어있는 physical page의 번호이다.
queue<int> emptyPhysicalPageNumber;


inline int getBlockNumberByPageNumber(long page){
	return page / N_PAGES_PER_BLOCK;
}

inline int getPageOffsetByPageNumber(long page){
	return page % N_PAGES_PER_BLOCK;
}

char *bit2cap(int b)
{
	static char *unit[] = { "", "K", "M", "G", "T", "P", "E" };
	static char buf[32];

	int u = b / 10;
	if (u > 6)
		return "<Too Big>";
	sprintf(buf, "%d%s", (1 << (b - u * 10)), unit[u]);
	return buf;
}

void show_info(void)
{
	printf("SSD capacity:\t\t%sB\n", bit2cap(SSD_SHIFT));
	printf("Page size:\t\t%sB\n", bit2cap(PAGE_SHIFT));
	printf("Pages / Block:\t\t%d pages\n", N_PAGES_PER_BLOCK);
	printf("Block size:\t\t%sB\n", bit2cap(PAGES_PER_BLOCK_SHIFT + PAGE_SHIFT));
	printf("OP ratio:\t\t%d%%\n", OP_RATIO);
	printf("Physical Blocks:\t%s (%d)\n", bit2cap(BLOCKS_SHIFT), N_BLOCKS);
	printf("User Blocks:\t\t%d\n", N_USER_BLOCKS);
	printf("OP Blocks:\t\t%d\n", N_OP_BLOCKS);
	printf("PPNs:\t\t\t%s (%d)\n", bit2cap(PPN_SHIFT), N_PPNS);
	printf("LPNs:\t\t\t%d\n", N_LPNS);
	printf("Total runs:\t\tx%d\n", N_RUNS);
	long long int actualcapacity = N_LPNS;
	long long int nPageSize = N_PAGE_SIZE;
	actualcapacity *= nPageSize;
	printf("Actual capacity:\t%ld Bytes\n\n", actualcapacity);
}

void show_stat(void)
{
	printf("\nResults ------\n");
	printf("Host writes:\t\t%ld\n", s.host_write);
	printf("GC writes:\t\t%ld\n", s.gc_write);
	printf("Number of GCs:\t\t%d\n", s.gc);
	printf("Valid pages per GC:\t%.2f pages\n", (double)s.gc_write / (double)s.gc);
	printf("WAF:\t\t\t%.2f\n", (double)(s.host_write + s.gc_write) / (double)s.host_write);
}

void init(void)
{
	s.gc = 0;
	s.host_write = 0;
	s.gc_write = 0;
	srand(0);
	nand_init(N_BLOCKS, N_PAGES_PER_BLOCK);

	//L2PBlockmap, P2LBlockmap 초기화
	memset(L2PPagemap, -1, sizeof(L2PPagemap));
	memset(P2LPagemap, -1, sizeof(P2LPagemap));

	memset(inValidNumInBlock, 0, sizeof(inValidNumInBlock));

	
	//맨처음 spareBlock의 번호는 마지막 블록이다.
	spareBlockNumber = N_BLOCKS - 1;

	for (int i = 0; i < (N_BLOCKS - 1) * N_PAGES_PER_BLOCK; i++)
		emptyPhysicalPageNumber.push(i);
}

long get_lpn()
{

	// rand() in MS Visual Studio generates a random number between 0 and 32767.
	//Random LPNs
	return (rand() << 15 | rand()) % N_LPNS;

	////Sequence LPNs
	//static unsigned long x = 0;
	//return (long)(x++ % N_LPNS);
}

//spare가 아닌 block에 write를 한다.
void Nand_Write_First_Time(long lpn){

	//빈 physical block을 얻는다.
	
	int candPhysicalPage = emptyPhysicalPageNumber.front();
	emptyPhysicalPageNumber.pop();

	P2LPagemap[candPhysicalPage] = lpn;
	L2PPagemap[lpn] = candPhysicalPage;
	return;
}

void Nand_Write_Non_First_Time(long lpn){
	//기존의 것을 invalid로 바꿔주고
	P2LPagemap[L2PPagemap[lpn]] = invalid;

	//그 블럭내의 invalid page 숫자를 1 올려줌.
	inValidNumInBlock[L2PPagemap[lpn] / N_PAGES_PER_BLOCK]++;
	Nand_Write_First_Time(lpn);
}

//invalid page의 숫자가 가장 많은 physical block의 번호를 반환
int getMostInvalidPageBlock() {

	int num = -1, ret;
	for (int i = 0; i < N_BLOCKS; i++) {
		if (i != spareBlockNumber && num < inValidNumInBlock[i]) {
			num = inValidNumInBlock[i];
			ret = i;
		}
	}
	return ret;
}

//victim block 과 spare block을 바꾼다.
void changeVictimAndSpare() {
	int victimBlock = getMostInvalidPageBlock();

	//valid한 page의 logical 번호를 가지고 있는다.
	vector<int> validPage;

	//valid page의 목록을 모은다.
	for (int i = 0; i < N_PAGES_PER_BLOCK; i++) {
		if (P2LPagemap[victimBlock + i] != invalid) {
			validPage.push_back(P2LPagemap[victimBlock + i]);
		}

	}

	//spareBlock에 valid한 정보를 넣어준다.
	for (int i = 0; i < validPage.size(); i++) {
		P2LPagemap[spareBlockNumber + i] = validPage[i];
		L2PPagemap[validPage[i]] = spareBlockNumber + i;
		s.gc_write++;
	}

	//spareBlock의 남는 부분을 emptypage의 목록에 넣어준다.
	for (int i = validPage.size(); i < N_PAGES_PER_BLOCK; i++) {
		emptyPhysicalPageNumber.push(i + spareBlockNumber);
	}

	s.gc++;

	for (int i = 0; i < N_PAGES_PER_BLOCK; i++) {
		//아무것도 쓰여지지 않았다는 것을 표시해준다.
		P2LPagemap[victimBlock + i] = -1;
		
		//emprtpage의 목록에 넣어준다.
		emptyPhysicalPageNumber.push(i + victimBlock);
	}

	//victim block을 spare block으로 바꾸어준다.
	spareBlockNumber = victimBlock;

}

//L2Ppagemap[lpn]에 기록이 되어있으면 true, 없으면 false
bool isPageMapTableExist(long lpn){
	return L2PPagemap[lpn] != -1;
}

//data block이 다 찼으면 true. 아니면 false
bool checkDataBlockisFull(){
	return emptyPhysicalPageNumber.size() == 0;
}



//Block 단위로 MapTable 관리
void write_lpn(long lpn)
{
	//1. BlockMapTable에 없는 경우 그냥 data를 써주고 return 한다.
	if (!isPageMapTableExist(lpn)){
		if (checkDataBlockisFull()) {
			//spare block과 victim block을 바꾸어 준다.
			changeVictimAndSpare();
		}
		Nand_Write_First_Time(lpn);
		return;
	}
	//2. BlockMapTable에 있는 경우. 다른 곳에 data를 써주고 이미 있는 곳에는 invalid 표시를 한다.
	else{
		//1. spare block을 바꿔줘야 하는지 check해준다. 
		//만약 바꿔줘야 한다면 바꾸는 logic을 실행
		if (checkDataBlockisFull()){
			//spare block과 victim block을 바꾸어 준다.
			changeVictimAndSpare();
		}
		//2. 지금 다시 write.
		
		Nand_Write_Non_First_Time(lpn);
		return;
	}
}


void sim()
{
	long lpn;

	while (s.host_write < LPN_COUNTS)
	{
		lpn = get_lpn();
		write_lpn(lpn);
		s.host_write++;
		//printf("%d %d\n", s.host_write, N_LPNS);
		if (s.host_write % N_LPNS == 0)
			printf("[Run %d] host %ld, valid page copy %ld, GC# %d, WAF=%.2f\n",
			(int)s.host_write / N_LPNS,
			s.host_write, s.gc_write, s.gc,
			(double)(s.host_write + s.gc_write) / (double)s.host_write);
	}
}

int main(void)
{
	freopen("output.txt", "w", stdout);
	init();
	show_info();
	sim();
	show_stat();
	return 0;
}


