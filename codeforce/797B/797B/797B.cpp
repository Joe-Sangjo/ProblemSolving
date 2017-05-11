#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
int dp[100001][2];
//[index][홀수면 1 and 짝수면 0]
//index에서 시작하는 even or odd의 최댓값
int solve(int index, int isOdd) {
	//cout << index << endl;

	int& ret = dp[index][isOdd];

	if (ret != 0xAAAAAAAA) return ret;

	//
	if (isOdd) {

	}

	for (int next = index + 1; next < n; next++) {
		int temp = solve(next) + arr[index];
		if (temp % 2) {
			ret = max(ret, temp);
		}
	}
	
	return ret;
}

int main() {

	freopen("input.txt", "r", stdin);
	cin >> n;

	memset(dp, 0xAA, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		arr.push_back(temp);
	}

	//cout << dp[0][0] << endl;

	//cout << dp[0] << endl;
	/*int ret = init;

	for (int i = 0; i < n; i++) {
		int temp = solve(i);
		if(temp % 2)
			ret = max(ret, solve(i));
	}
	cout << ret << endl;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0)
			sum += arr[i];
	}
	cout << sum << endl;
	
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;*/

	return 0;
}