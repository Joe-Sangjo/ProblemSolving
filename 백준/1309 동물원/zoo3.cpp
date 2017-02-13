#include <iostream>
#include <cstring>


using namespace std;

int N;
int cache[100001][2];
int lion(int cage,int before_state);
int main(){
	memset(cache, -1, sizeof(cache));
	// cin>>N;
	N = 4;

	cout<< lion(1,0)<<endl;

	return 0;
}

int lion(int cage,int before_state){

	if(cage == N){
		if(before_state){
			return 2;
		}
		else{
			return 3;
		}
	}

	int& ret = cache[cage][before_state];

	if(ret != -1) return ret;
	ret = 0;
	if(before_state){
		ret += lion(cage + 1, 1);
	}
	else{
		ret += 2 * lion(cage + 1, 1);
	}
	ret += lion(cage + 1, 0);
	return ret % 9901;
}