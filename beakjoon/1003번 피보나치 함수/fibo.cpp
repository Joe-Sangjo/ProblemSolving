#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int N;
int cachefor0[41];
int cachefor1[41];

int cntfor0(int n);
int cntfor1(int n);
int main(){

	freopen("input.txt","r",stdin);
	memset(cachefor1, -1, sizeof(cachefor1));
	memset(cachefor0, -1, sizeof(cachefor0));

	int TC;
	cin>>TC;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N;
		cout<<cntfor0(N)<<" "<<cntfor1(N)<<endl;
	}
	return 0;
}

int cntfor0(int n){
	if(n == 0) return 1;
	if(n < 0 ) return 0;
	if(n == 1) return 0;
	int& ret = cachefor0[n];

	if(ret != -1) return ret;

	return ret = cntfor0(n-1) + cntfor0(n-2);
}

int cntfor1(int n){
	if(n == 1) return 1;
	if(n < 1) return 0;

	int& ret = cachefor1[n];

	if(ret != -1) return ret;

	return ret = cntfor1(n-1) +cntfor1(n-2);
}