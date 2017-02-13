#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool areFreinds[10][10];
int n;
int m;
int countParings(bool taken[10]);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);
	int T;
	cin>>T;
	int f1, f2;
	for(int test_case = 0; test_case < T; test_case++){
		cin>>n>>m;
		memset(areFreinds, false, 100*sizeof(bool));
		for(int i=0;i<m;i++){
			cin>>f1>>f2;
			areFreinds[f1][f2] = true; areFreinds[f2][f1] = true;
		}
		bool taken[10];
		memset(taken, false, 10*sizeof(bool));
		
		cout<<countParings(taken)<<endl;
	}
	return 0;
}

int countParings(bool taken[10]){
	
	int firstFree = -1;
	for(int i = n-1; i >= 0 ; i--){
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}

	if(firstFree == -1) return 1;
	int ret = 0;

	for(int pairWith = firstFree-1; pairWith >= 0; pairWith--){
		if(!taken[pairWith] && areFreinds[firstFree][pairWith]){
			taken[firstFree] = taken[pairWith] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}