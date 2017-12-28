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
#include "nand.h"

using namespace std;


#define SSD_SHIFT	          	32
#define PAGE_SHIFT	           	12
#define PAGES_PER_BLOCK_SHIFT	7
#define OP_RATIO				7
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

//spare block인지 아닌지
bool isSpareBlock[N_BLOCKS + 1];
vector<int> SpareBlockList;
vector<int> inValidNumInBlock;

int writtenDataBlockNum;

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

	memset(isSpareBlock, false, sizeof(isSpareBlock));
	writtenDataBlockNum = 0;

	inValidNumInBlock = vector<int>(N_BLOCKS + 1, 0);

	//spare초기화
	for (int i = N_LPNS; i < N_PPNS; i++){
		isSpareBlock[i] = true;
		SpareBlockList.push_back(i);
	}
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
	srand(0);
	int candPhysicalPage;
	while (true){
		candPhysicalPage = rand() % (N_BLOCKS * N_PAGES_PER_BLOCK);
		//그 physical Page가 비어있고, spare가 아니면,
		if (P2LPagemap[candPhysicalPage] == -1 && !isSpareBlock[candPhysicalPage / N_PAGES_PER_BLOCK]){

			P2LPagemap[candPhysicalPage] = lpn;

			L2PPagemap[lpn] = candPhysicalPage;

			nand_write(candPhysicalPage / N_PAGES_PER_BLOCK, candPhysicalPage % N_PAGES_PER_BLOCK, 1, lpn);

			writtenDataBlockNum++;
			return;
		}
	}
}

void Nand_Write_Non_First_Time(long lpn){
	//기존의 것을 invalid로 바꿔주고
	P2LPagemap[L2PPagemap[lpn]] = invalid;

	//그 블럭내의 invalid page 숫자를 1 올려줌.
	inValidNumInBlock[P2LPagemap[L2PPagemap[lpn]] / N_PAGES_PER_BLOCK]++;

	Nand_Write_First_Time(lpn);
}


//L2Ppagemap[lpn]에 기록이 되어있으면 true, 없으면 false
bool isPageMapTableExist(long lpn){
	return L2PPagemap[lpn] != -1;
}

//data block이 다 찼으면 true. 아니면 false
bool checkDataBlockisFull(){
	return writtenDataBlockNum >= N_LPNS;
}



//Block 단위로 MapTable 관리
void write_lpn(long lpn)
{
	//1. BlockMapTable에 없는 경우 그냥 data를 써주고  return 한다.
	if (!isPageMapTableExist(lpn)){
		Nand_Write_First_Time(lpn);
		return;
	}


	//2. BlockMapTable에 있는 경우. 다른 곳에 data를 써주고 이미 있는 곳에는 invalid 표시를 한다.
	if (isPageMapTableExist(lpn)){

		//1. spare block을 바꿔줘야 하는지 check해준다. 
		//만약 바꿔줘야 한다면 바꾸는 logic을 실행
		if (checkDataBlockisFull()){



		}

		//2. 지금 다시 write.
		Nand_Write_Non_First_Time(lpn);


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
		if (s.host_write % N_LPNS == 0)
			printf("[Run %d] host %ld, valid page copy %ld, GC# %d, WAF=%.2f\n",
			(int)s.host_write / N_LPNS,
			s.host_write, s.gc_write, s.gc,
			(double)(s.host_write + s.gc_write) / (double)s.host_write);
	}
}

int main(void)
{
	init();
	show_info();
	sim();
	show_stat();
	return 0;
}


