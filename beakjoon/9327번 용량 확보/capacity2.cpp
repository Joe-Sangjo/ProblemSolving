#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n, e;
int S[101];
int dp[101][200001];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n>>e;
		int sum = 0;
		for(int i = 0; i < n ; i++){
			cin>>S[i];
			sum +=S[i];
		}
		if(sum * 2 < e){
			cout<<"FULL"<<endl;
			continue;
		}
		
		sort(S, S + n);
		
		memset(dp, 0, sizeof(dp));
		
		for(int capacity = 0; capacity <= sum; capacity++){
			for(int )
		}


	}



	return 0;
}