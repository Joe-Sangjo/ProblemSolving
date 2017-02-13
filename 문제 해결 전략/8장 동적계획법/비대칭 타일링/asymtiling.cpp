#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MOD 1000000007
int n;
long long cache[101];
long long cache2[101];
long long cache3[101];
long long tiling(int width);
long long symetrytiling(int width);
long long asym(int width);
int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;

		memset(cache,-1,sizeof(cache));
		memset(cache2,-1,sizeof(cache2));
		// cout<<n<<endl;
		// cout<<tiling(n)-symetrytiling(n)<<endl;
		// cout<<tiling(n) - symetrytiling(n)<<endl;
		// cout<<symetrytiling(n)<<endl;
		cout<<asym(n)<<endl;
	}

	return 0;
}
long long asym(int width){
	return (tiling(width) - symetrytiling(width) + MOD) % MOD;
}
long long tiling(int width){
	if(width == 1) return 1;
 
	if(width == 2) return 2;
	long long&ret = cache[width];

	if(ret != -1) return ret;
	
	return ret = (tiling(width-1) + tiling(width-2)) % MOD;
}

long long symetrytiling(int width){

	if(width == 1) return 1;

	if(width == 2) return 2;

	if(width == 3) return 1;

	if(width == 4) return 3;
	long long& ret = cache2[width];

	if(ret != -1) return ret;
	
	return ret = (symetrytiling(width-2) +  symetrytiling(width-4)) % MOD;

}
