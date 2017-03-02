#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int INF = 9999999;

int N;
int cache[100000];
int represent(int n);
int main(){

	// cin>>N;
	N =100;

	memset(cache, -1, sizeof(cache));
	cout<<represent(N)<<endl;
	// cout<<N<<endl;
	return 0;
}

int represent(int n){

	if(n == 0) return 0;

	int& ret = cache[n];

	if(ret != -1) return ret;
	
	ret = INF;

	for(int i = 1; i*i <= n; i++){
		ret = min(ret, represent(n-i*i) + 1);
	}
	
	return ret;
}

