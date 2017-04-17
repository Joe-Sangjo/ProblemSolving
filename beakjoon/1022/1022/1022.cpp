#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10010][10010];
int MAXNUM = 5001;
int numToIndex(int num){
	return num + MAXNUM;
}
int indexToNum(int index){
	return index - MAXNUM;
}
void print1(int num){
	printf("%1d ", num);
}
void print2(int num){
	printf("%2d ", num);
}
void print3(int num){
	printf("%3d ", num);
}
void print4(int num){
	printf("4d ", num);
}
void print5(int num){
	printf("%5d ", num);
}
void print(int num, int log){
	switch(log){
		case 1:
			print1(num);
		break;
		case 2:
			print2(num);
		break;
		case 3:
			print3(num);
		break;
		case 4:
			print4(num);
		break;
		case 5:
			print5(num);
		break;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(a, -1, sizeof(a));
	int num = 1;
	a[numToIndex(0)][numToIndex(0)] = num++;

	int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
	// r1 = -5000; r2 = -4990; c1 = -5000; c2 = -4997;
	//Í∞Ä??Î∞îÍπ• ÍªçÏßà
	for(int shell = 1; shell <= MAXNUM; shell++){

		//?ÑÎ°ú ?¨ÏïÑÍ∞?
		for(int y = shell - 1; y >= -shell; y--){
			a[numToIndex(y)][numToIndex(shell)] = num++;			
		}

		//?ºÏ™Ω?ºÎ°ú Í∞?
		for(int x = shell - 1; x >= -shell ;x--){
			a[numToIndex(-shell)][numToIndex(x)] = num++;
		}

		//Î∞ëÏúºÎ°??¥Î†§??
		for(int y = -shell + 1; y <= shell; y++){
			a[numToIndex(y)][numToIndex(-shell)] = num++;
		}

		//?§Î•∏Ï™ΩÏúºÎ°?Í∞?
		for(int x = -shell + 1; x <= shell; x++){
			a[numToIndex(shell)][numToIndex(x)] = num++;
		}
	}

	int zari = -1;
	for(int y = numToIndex(r1); y <= numToIndex(r2); y++){
		for(int x = numToIndex(c1) ; x <= numToIndex(c2); x++){
			zari = max(zari, a[y][x]);
		}
	}

	int log = 0;
	while(zari){
		zari /= 10; log++;
	}
	for(int y = numToIndex(r1); y <= numToIndex(r2); y++){
		for(int x = numToIndex(c1) ; x <= numToIndex(c2); x++){
			print(a[y][x], log);
		}
		cout<<endl;
	}

	return 0;
}