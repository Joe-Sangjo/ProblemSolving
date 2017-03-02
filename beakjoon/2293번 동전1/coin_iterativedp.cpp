#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k;
int value[101];
int dp[10001];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	cin>>n>>k;
	for(int i = 0; i < n ; i++){
		cin>>value[i];
		// cout<<value[i]<<" ";
	}
	sort(value, value + n);
	dp[0] = 1;

	for(int coin = 0; coin < n; coin++){
		for(int money = 1; money <= k; money++){
			if(money >= value[coin]){
				dp[money] += dp[money - value[coin]];
			}	
		}
	}
	
	cout<<dp[k]<<endl;
	return 0;
}