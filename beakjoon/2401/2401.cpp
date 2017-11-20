#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define max(a, b) a > b ? a : b;

using namespace std;
string Long;
vector<string> Short;
int n;

vector<vector<int> > matching;

vector<int> getPi(string &N) {

	int m = N.size(), matched = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {

		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];

		if (N[i] == N[matched])
			pi[i] = ++matched;
	}
	return pi;
}

void kmpSearch(string &H, string &N, int num) {

	int n = H.size(), m = N.size(), matched = 0;

	vector<int> pi = getPi(N);
	for (int i = 0; i < n; i++) {

		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];

		if (H[i] == N[matched]) {
			
			matched++;
			if (m == matched) {
				//cout << i - m + 1 << "    " << matching.size() << endl;
				matching[i - m + 1].push_back(num);
				matched = pi[matched - 1];
			}
		}
	}
}

int dp[100010];

int solve(int pos) {
	if (pos >= Long.size()) return 0;

	int& ret = dp[pos];

	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < matching[pos].size(); i++) {

		int shortNum = matching[pos][i];
		
		int nextPos = pos + Short[shortNum].size();
		ret = max(ret, solve(nextPos) +  Short[shortNum].size() );
	}

	return ret;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
	cin >> Long;
	cin >> n; Short.resize(n + 1);
	matching = vector<vector<int> >(Long.size()+1);

	for (int i = 0; i < n; i++) {
		cin >> Short[i];
		kmpSearch(Long, Short[i], i);
	}

	for (int i = 0; i < matching.size(); i++) {
		for (int j = 0; j < matching[i].size(); j++) {
			cout << matching[i][j] << " ";
		}
		cout << endl;
	}
	memset(dp, -1, sizeof(dp));

	int ret = 0;
	for (int i = 0; i < Long.size(); i++) {
		ret = max(ret, solve(i));
	}
	
	cout << ret << endl;

	

	return 0;
}