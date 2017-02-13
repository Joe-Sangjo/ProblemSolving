#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;
int n;
long long count(int idx, int num);
long long dp[70][11];
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n;
		// n = 45;
		memset(dp, -1, sizeof(dp));
		long long ret = 0;
		for(int i = 0 ; i < 10; i++){
			ret += count(0, i);
		}
		cout<<ret<<endl;
	}

	return 0;
}
long long count(int idx, int num){
	if(idx == n - 1) return 1;

	long long& ret = dp[idx][num];

	if(ret != -1) return ret;

	ret = 0;

	for(int i = num; i < 10; i++){
		ret += count(idx + 1, i);
	}
	return ret;

}