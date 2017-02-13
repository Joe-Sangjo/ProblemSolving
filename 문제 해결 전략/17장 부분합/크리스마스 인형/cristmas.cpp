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
int D[100001];
ll Psum[100001];
int dp[100001];
vector<pair<int, int> > ret;
vector<pair<int, int> > problem1();



int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	while(TC--){
		ret.clear();
		memset(dp, 0, sizeof(dp));
		cin>>N>>K;
		for(int i = 1; i <= N; i++){
			cin>>D[i];

		}
		Psum[0] = 0;
		Psum[1] = D[1];
		for(int i = 2; i <= N; i++){
			Psum[i] += Psum[i-1] + D[i];
		}

		ret = problem1();
		int n = ret.size();
		cout<<n % MOD<<endl;


		dp[n-1] = 1;
		int dpret = 1;
		for(int start = n - 2; start >= 0; start--){
			for(int next = start + 1; next < n; next++){
				if(ret[start].second < ret[next].first){
					dp[start] = max(dp[start], dp[next] + 1);
				}
			}
			dpret = max(dpret, dp[start]); 

		}
		cout<<dpret<<endl;

	}

	return 0;
}

vector<pair<int, int> > problem1(){
	vector<pair<int, int> > ret1;

	for(int end = 1; end <= N; end++){
		for(int start = 1; start <= end; start++){
			if((Psum[end] - Psum[start - 1]) % K == 0){
				ret.push_back(make_pair(start, end));
			}
		}
	}

	sort(ret.begin(), ret.end());
	return ret;

}
