#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

#define MOD 20091101
typedef long long int ll;

using namespace std;

int N, K;
ll n;
int D[100001];
ll Psum[100001];
int dp[100001];


int solve(int end);

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	while(TC--){
		memset(dp, -1, sizeof(dp));
		cin>>N>>K;
		n = 0;
		for(int i = 1; i <= N; i++){
			cin>>D[i];

		}
		Psum[0] = 0;
		Psum[1] = D[1];
		for(int i = 2; i <= N; i++){
			Psum[i] += Psum[i-1] + D[i];
		}
		vector<vector<int> > ret;
		vector<int> dummy;
		ret.push_back(dummy);
		for(int end = 1; end <= N; end++){
			vector<int> r;
			r.push_back(0);
			for(int start = 1; start <= end; start++){
				if((Psum[end] - Psum[start - 1]) % K == 0){
					r.push_back(start);
					// cout<<start<<" "<<end<<endl;
					n++;
				}
			}
			ret.push_back(r);
		}
		// int n = ret.size();
		cout<<n % MOD<<endl;
		// for(int i = 1; i <= N; i++){
		// 	for(int j = 1; j < ret[i].size(); j++){
		// 		cout<<ret[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		// dp[n - 1] 

		dp[1] = 1;

		int dpret = 1;
		for(int end = 1; end <= n; end++){
			for(int start = 1; start <= ret[end].size(); start++){
				if(dp[ret[end][start]] == -1){
					int i = ret[end][start];
					while(dp[i] != -1){i--;}
					dp[end] = max(dp[end], dp[i] + 1);
					
				}
			}
			dpret = max(dpret, dp[end]);
		}
		cout<<dpret<<endl;

	}

	return 0;
}


int solve(int end){

}