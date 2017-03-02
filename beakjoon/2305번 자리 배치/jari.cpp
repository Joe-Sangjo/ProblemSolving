#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int N, K;
int seat[41];
int seating(int n, int num);
int dp[41][41];
int main(){
	freopen("input.txt","r",stdin);
	memset(dp, -1, sizeof(dp));
	cin>>N>>K;







	return 0;
}

int seating(int n, int num){
	if(n == N) return 1;

	if(n == N + 1) return 0;
	
	int& ret = dp[n][num];

	if(ret != -1) return ret;

	ret = 0;

	if(n == num){
		ret = 

	}
	else{



	}
}