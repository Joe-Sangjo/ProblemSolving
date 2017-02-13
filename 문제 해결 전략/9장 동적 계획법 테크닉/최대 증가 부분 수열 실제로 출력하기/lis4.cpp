#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int N;
int S[501];
int choices[501],cache[501];
int lis4(int start);
void reconstruct(int start, vector<int>& seq);
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N;
		for(int i = 0; i < N; i++){
			cin>>S[i];
			// cout<<S[i]<<" ";
		}
		memset(cache, -1, sizeof(cache));
		// cout<<endl;
		vector<int> record;
		cout<<lis4(-1) - 1<<endl;
		reconstruct(-1, record);
		// for(int i = 0; i < record.size(); i++){
		// 	cout<<record[i]<<" ";
		// }
		// cout<<endl;
		for(int i = 0; i < N; i++){
			cout<<choices[i]<<" ";
		}
		cout<<endl;
	}



	return 0;
}

int lis4(int start){
	int& ret = cache[start + 1];

	if(ret != -1) return ret;

	ret = 1;

	int bestNext = -1;

	for(int next = start + 1; next < N; next++){
		if(start == -1 || S[start] < S[next]){
			int cand = lis4(next) +1;
			if(cand > ret){
				ret = cand;
				bestNext = next;
			}
		}
	}
	choices[start + 1] = bestNext;
	return ret;
}
void reconstruct(int start, vector<int>& seq){
	if(start != -1) seq.push_back(S[start]);
	int next = choices[start + 1];
	if(next != -1) reconstruct(next, seq);
}