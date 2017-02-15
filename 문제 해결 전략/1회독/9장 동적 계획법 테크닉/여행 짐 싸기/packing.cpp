#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
int N, W;
string item[101];
int volume[101], julbak[101];
int c[101];
int packing(int idx, int w);
int dp[101][1001];
vector<int> picked;
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N>>W;
		for(int i = 0 ; i < N; i++){
			cin>>item[i]>>volume[i]>>julbak[i];

		}
		memset(c,-1,sizeof(c));
		memset(dp, -1, sizeof(dp));

		int ret = 0;
		int iii;
		for(int i = 0; i < N; i++){
			vector<int> p1;
			int cand = packing(i,0);
			if(cand > ret){
				ret = cand;
				iii = i;
			}
		}
		cout<<ret<<" ";
		
		vector<int> picked;
		int pre = iii;

		while(c[pre] != -1){
			picked.push_back(pre);		
			// cout<<c[pre]<<" ";
			pre = c[pre];
		}
		cout<<picked.size() - 1<<endl;
		for(int i = 0 ; i <picked.size() - 1; i++){
			// cout<<picked[i]<<" ";
			cout<<item[picked[i]]<<endl;
		}
		// cout<<endl;

	}
	return 0;
}

int packing(int idx, int w){
	
	int& ret = dp[idx][w];

	if(ret != -1) return ret;

	ret = 0;
	int bestNext = -1;

	for(int next = idx + 1; next < N; next++){
		if(w + volume[idx] <= W){
			int cand = packing(next, w + volume[idx]) + julbak[idx];
			if(cand > ret){
				ret = cand;
				bestNext = next;
			}
		}
	}
	c[idx] = bestNext;
	return ret;
}