#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;
int N, M;
int type_Coin[21];
int count(int idx, int now_price);
int cache[21][10001];
int main(){

	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0 ;test_case < TC; test_case++){
		cin>>N;
		memset(cache, -1, sizeof(cache));
		for(int i = 0 ; i < N ; i++){
			cin>>type_Coin[i]; 
		}
		cin>>M;
		cout<<count(0,0)<<endl;
		// cout<<endl<<endl;
	}




	return 0;
}

int count(int idx, int now_price){
	// cout<<type_Coin[idx]<<" "<<now_price<<endl;
	if(idx == N - 1){
		if((M - now_price) % type_Coin[idx] == 0)
			return 1;
		else{
			return 0;
		}
	}

	// if(now_price == M) return 1;

	int& ret = cache[idx][now_price];

	if(ret != -1) return ret;

	ret = 0;

	for(int i = 0 ; (now_price + i * type_Coin[idx]) <= M; i++){
		ret += count(idx + 1, now_price + i * type_Coin[idx]);
	}
	// if(idx == 1) cout<<ret<<endl;
	return ret;

}