#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;
vector<int> arr;
int dp[1001];
#define max(a, b) a > b ? a : b

int solve(int idx) {

	int& ret = dp[idx];

	if (ret != -1) return ret;

	ret = 1;

	for (int next = idx + 1; next < n; next++) {
		if(arr[next] < arr[idx])
			ret = max(ret, solve(next) + 1);
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	arr = vector<int>(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		//printf("%d\n", arr[i]);
	}

	int ret = -1;

	for (int i = 0; i < n; i++) {
		ret = max(ret, solve(i));
	}

	printf("%d\n", ret);

	return 0;
}