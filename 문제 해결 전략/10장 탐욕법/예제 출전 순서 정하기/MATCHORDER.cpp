#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int NEGINF = -999999999;
int N;
int RUSIA[101];
int KOREA[101];
int cache[101][101];
int matching(int r, int k);
int main(){

	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>N;
		for(int i = 0; i < N; i++)
			cin>>RUSIA[i];
		for(int i = 0; i < N; i++)
			cin>>KOREA[i];
		memset(cache, -1, sizeof(cache));
		sort(RUSIA, RUSIA+N); sort(KOREA, KOREA+N);

		for(int i = 0; i < N; i++){
			// cout<<RUSIA[i]<<" ";
		}
		// cout<<endl;
		for(int i = 0; i < N; i++){
			// cout<<KOREA[i]<<" ";
		}
		// cout<<endl;
		int maxmatcing = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				maxmatcing = max( maxmatcing, matching(i,j));
			}
		}
		cout<<maxmatcing<<endl;
	}





	return 0;
}
int matching(int r, int k){
	
	if(r == N) return 0;

	int& ret = cache[r][k];

	if(ret != -1) return ret;
	
	if(RUSIA[r] > KOREA[k]) return ret = 0;

	ret = 1;

	for(int next_k = k + 1 ; next_k < N; next_k++){
		if(RUSIA[r+1] <= KOREA[next_k])
			ret = max(ret, matching(r+1, next_k)+1);
	}

	return ret;
}