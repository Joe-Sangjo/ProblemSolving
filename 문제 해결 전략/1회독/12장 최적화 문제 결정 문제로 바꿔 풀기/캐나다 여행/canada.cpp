#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int N, K;
int L[5001], M[5001], G[5001];
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N>>K;
		for(int i = 0 ; i < N; i++){
			cin>>L[i]>>M[i]>>G[i];
		}
		vector<int> direct;
		// int cnt = 0;
		for(int i = 0; i < N; i++){
			int data = L[i] - M[i];

			while(data != L[i]){
				direct.push_back(data);
				// cnt ++;
				data += G[i];
			}
			direct.push_back(data);
			// cnt++;
		}

		sort(direct.begin(), direct.end());
		cout<<direct[K-1]<<endl;
		// for(int i = 0; i < cnt; i++){
		// 	cout<<direct[i]<<" ";
		// }
		// cout<<endl;
	}





	return 0;
}