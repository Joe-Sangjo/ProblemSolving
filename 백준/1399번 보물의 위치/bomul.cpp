#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int K, M;
int P;
int dig(int n);
int getDig(int n);
int dp[100000];
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	for(int test_case = 0; test_case < TC; test_case++){
		cin>>K>>M;
		dp[0] = 1;
		P = 0;
		for(int i = 1; i < 100000; i++ ){

			dp[i] = dig(dp[i - 1] * M);
			// cout<<dp[i]<<" "<<i<<endl;
			if(dp[i] == 1){
				P = i;
				break;
			}
			if(dp[i - 1 ] == 9 && dp[i] == 9){
				P = -100;
				break;
			}		
		}
		int x = 0, y = 0;
		for(int i = 0; i < K; i++){
			if(i % 4 == 0){
				y += getDig(i);
			}
			else if(i % 4 == 1){
				x += getDig(i);
			}
			else if(i % 4 == 2){
				y -= getDig(i);
			}
			else{
				x -= getDig(i);
			}
		}
		cout<<x<<" "<<y<<endl;
	
	}
	return 0;
}

int dig(int n){
	int i;
	int array[6];
	while(n / 10 != 0){
		i = 0; 
		while(n / 10 != 0){
			array[i++] = n % 10;
			n /= 10;
			
		}
		for(int j = i - 1; j >= 0; j--){
			n += array[j];

		}
	}
	return n;
}

int getDig(int n){
	if(P != -100){
		return dp[n%P];
	}
	else{
		return 9;
	}
}