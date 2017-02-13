#include <iostream>
#include <cstdio>
#include <cstring>

#define min(a, b) a < b ? a : b;
const int INF = 987654321;
using namespace std;
int N;
int S;
int pSum[100001];
int dp[100001];
int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	cin>>N>>S;
	pSum[0] = 0;
	int buf;
	
	for(int i = 1; i <= N; i++){
		cin>>buf;
		pSum[i] = pSum[i-1] + buf;
	}
	memset(dp, -1, sizeof(dp));
	for(int end = 1; end <= N; end++){
		for(int start = end ; start >= 1; start--){
			if(pSum[end] - pSum[start -1 ] >= S){
				dp[end] = end - start + 1;
				break;
			}
		}
	}
	int ret = INF;
	for(int i = 1; i <= N; i++){
		if(dp[i] != -1)
            ret = min(ret, dp[i]);

	}

	if(ret >= INF){
		cout<<0<<endl;
	}
	else{
		cout<<ret<<endl;
	}
	return 0;
}