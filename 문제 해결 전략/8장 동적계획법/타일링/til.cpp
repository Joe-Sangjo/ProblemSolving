#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long cnt(int n);
long long cache[101];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;
	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;
		n= 9;
		memset(cache, -1, sizeof(cache));
		cout<<cnt(n)<<endl;
	}
	// cout<<endl<<endl<<recur<<endl;
	return 0;
}

long long cnt(int n){
	long long& ret = cache[n];
	if(ret != -1) return ret;

	if(n == 1) return ret = 1;
	if(n == 2) return ret = 2;
	return ret = (cnt(n-1)+cnt(n-2))%1000000007;
}