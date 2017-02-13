#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 10*1000*1000;
int cache[101][101];
int poly(int n, int first);
int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	int TC; cin>>TC;
	int n;
	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>n;
		memset(cache, -1 ,sizeof(cache));
		int ret=0;
		for(int i = 1; i <= n ; i ++){
			ret +=poly(n,i);
			ret %=MOD;
		}
		cout<<ret<<endl;
	}
	return 0;
}
int poly(int n, int first){
	if(n == first) return 1;

	int& ret = cache[n][first];
	if(ret != -1) return ret;

	ret = 0;

	for(int second = 1; second <= n-first; second++){
		int add = second + first - 1;
		add *=poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}