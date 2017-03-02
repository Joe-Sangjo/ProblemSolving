#include <iostream>
#include <cstring>

using namespace std;
const long long MOD = 1000000000;
long long cache[101][11];
long long easy_stair(int idx, int number);
int N;
int main(){
	
	// cin>>N;
	N = 5;
	memset(cache, -1, sizeof(cache));
	long long ret = 0;
	for(int i = 1; i <= 9; i++){
		ret += easy_stair(1,i);
	}

	cout<<ret % MOD<<endl;

	return 0;
}

long long easy_stair(int idx, int number){
	if(idx == N) return 1;

	long long&ret = cache[idx][number];

	if(ret != -1) return ret;

	ret = 0; 

	if(number != 0){
		ret += easy_stair(idx + 1, number - 1);
	}
	if(number != 9){
		ret += easy_stair(idx + 1, number + 1);
	}
	return ret % MOD;
}