#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int T[15], P[15];

int dp[16];

int solve(int here) {
	//±âÀú»ç·Ê
	if (here + T[here] >= n + 1) return 0;

	int& ret = dp[here];

	if (ret != -1) return ret;

	ret = P[here];

	for (int next = here + T[here]; next < n; next++) {

		ret = max(ret, solve(next) + P[here]);

	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
		//cout << T[i] << " " << P[i] << endl;
	}

	memset(dp, -1, sizeof(dp));


	int ret = 0;

	for (int i = 0; i < n; i++) {

		ret = max(ret, solve(i));
	}
	cout << ret << endl;

	/*for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	return 0;
}