#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>


using namespace std;
const int NEGINF = -2100000000;
int n;
int number[51];
int dp[51][51];
int numberGame(int left, int right);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>number[i];
			// cout<<number[i]<<" ";
		}
		// cout<<endl;
		for(int i = 0; i < 51; i++){
			for(int j = 0; j < 51; j++){
				dp[i][j] = NEGINF;
			}
		}
		cout<<numberGame(0, n - 1)<<endl;
	}

	return 0;
}

int numberGame(int left, int right){
	if(left > right) return 0;

	int& ret = dp[left][right];

	if(ret != NEGINF) return ret;

	ret = max(ret, number[left] - numberGame(left + 1, right));

	ret = max(ret, number[right] - numberGame(left, right - 1));

	if(right - left >= 2){
		ret = max(ret, -numberGame(left +2, right));
		ret = max(ret, -numberGame(left,right - 2));
	}

	return ret;

}