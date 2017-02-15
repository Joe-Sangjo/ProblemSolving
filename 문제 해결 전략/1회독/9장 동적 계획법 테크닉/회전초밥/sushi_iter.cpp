#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
int price[21], preference[21];
int dp[201];
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

		m/= 100;
		
		int ret = 0;
		dp[0] = 0;
		for(int budget = 1; budget <= m; budget++){
			// int cand = 0;
			dp[budget % 201] = 0;
			// cout<<budget<<endl;
			for(int dish = 0; dish < n; dish++){
				// cout<<budget<<"  "<<dish<<endl;
				if(budget >= price[dish])
					dp[budget % 201] = max(dp[budget % 201], dp[(budget - price[dish])%201] + preference[dish]);
			}
			// dp[budget % 201] = cand;
			ret = max(ret, dp[budget % 201]);		
		}

		cout<<ret<<endl;
	}
	return 0;
}
