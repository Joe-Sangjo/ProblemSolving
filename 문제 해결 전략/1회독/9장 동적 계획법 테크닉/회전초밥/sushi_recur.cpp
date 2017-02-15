#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
int price[21], preference[21];
int sushi(int idx,int rest);
int dp[21][40001];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			cin>>price[i]>>preference[i];
			price[i] /= 100;
			// cout<<price[i]<<" "<<preference[i]<<endl;
		}
		// cout<<endl;
		memset(dp, -1, sizeof(dp));

		int ret = 0;
		if(m > 40000) m = 40000;
		for(int i = 0; i < n ; i++){
			ret = max(ret, sushi(i, m) + preference[i]);
		}
		cout<<ret<<endl;
	}
	return 0;
}

int sushi(int idx,int rest){

	int& ret = dp[idx][rest];

	if(ret != -1) return ret;

	ret = 0;

	for(int next = idx + 1; next < n; next++){
		if(rest - price[next] >= 0){
			ret = max(ret ,sushi(next, rest - price[next]) + preference[next]);
		}
	}
	return ret;

}