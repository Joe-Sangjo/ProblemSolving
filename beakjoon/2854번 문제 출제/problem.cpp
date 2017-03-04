#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;
int N;
int array[2][100001];
ll set(int y, int idx);
ll dp[2][100001];
int main(){
	freopen("input.txt","r",stdin);
	cin>>N;
	for(int i = 0; i < N ; i++){
		cin>>array[0][i];
	}

	for(int i = 0 ; i < N -1 ; i++){
		cin>>array[1][i];
	}
	memset(dp, -1, sizeof(dp));


	ll ret = 0;

	ret += set(0, 1) % MOD;
	ret += set(1, 1) % MOD;

	cout<<ret<<endl;

	return 0;
}

ll set(int y, int idx){
	cout<<
	if(idx == N && y == 0) return array[y][idx];

	if(idx == N && y == 1) return array[y][idx - 1];

	if(idx > N) return 0;

	ll& ret = dp[y][idx];

	if(ret != -1) return ret;

	ret = 0;

	ret += array[y][idx] * set(0, idx + 1) % MOD;

	ret += array[y][idx] * set(1, idx + 1) % MOD;

	if(y == 0){
		ret += array[y][idx] * array[1][idx] * set(0, idx + 2) % MOD;
		ret += array[y][idx] * array[1][idx] * set(1, idx + 2) % MOD;

	}
	else{
		ret += array[y][idx] * (array[y][idx] - 1) * set(0, idx + 2) % MOD;
		ret += array[y][idx] * (array[y][idx] - 1) * set(1, idx + 2) % MOD;

	}
	return ret;
}