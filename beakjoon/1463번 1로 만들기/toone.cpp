#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int N;
const int INF = 99999999;
int cache[10000000];
int toOne(int n);
int main(){

	// cin>>N;
	N = 40;

	memset(cache, -1, sizeof(cache));
	// for(int i = 1; i < 20; i++)
	// 	cout<<i<<"    "<<toOne(i)<<endl;
	cout<<toOne(N)<<endl;



	return 0;
}

int toOne(int n){
	if(n == 1) return 0;
	if(n <= 0) return INF;

	int& ret = cache[n];

	if(ret != -1) return ret;

	ret = INF;
	if(n%3 == 0){
		ret = min(ret, toOne(n/3) + 1);
	}
	if(n%2 == 0){
		ret = min(ret, toOne(n/2) + 1);
	}
	ret = min(ret, toOne(n-1) + 1);

	return ret;
}