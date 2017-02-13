#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int S[501];
int lis3(int start);
int cnt();
int cahce[501];
int CNT[501];
int maxlen;
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N>>K;
		for(int i = 0; i < N; i++){
			cin>>S[i];
		}
		memset(cahce, -1, sizeof(cahce));
		maxlen = lis3(-1) - 1;
		cout<<maxlen<<endl;
	}




	return 0;
}

int lis3(int start){
	
	int& ret = cahce[start + 1];
	
	if(ret != -1) return ret;

	ret = 1;

	for(int next = start + 1; next < N; next++){
		if(start == -1 || S[start] < S[next]){
			ret = max(ret, lis3(next) + 1);
		}
	}

	return ret;
}

int cnt(){

	
}