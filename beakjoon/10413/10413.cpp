#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string S;
int d, N;
vector<int> SA, LCP;
vector<int> group;
bool cmp(int i, int j) {
	if (group[i] != group[j]) return group[i] < group[j];

	i += d; j += d;
	return (i < N && j < N) ? group[i] < group[j] : i > j;
}
void getSA() {

	for (int i = 0; i < N; i++) {
		SA[i] = i;
		group[i] = S[i];
	}

	for (d = 1; ; d *= 2) {
		sort(SA.begin(), SA.end(), cmp);
		vector<int> newGroup(N, 0);

		for (int i = 0; i < N - 1; i++)
			newGroup[i + 1] = newGroup[i] + cmp(SA[i], SA[i + 1]);
	
		for (int i = 0; i < N; i++)
			group[SA[i]] = newGroup[i];

		if (newGroup[N - 1] == N - 1) break;
	}
}

void getLCP() {
	for (int i = 0, k = 0; i < N; i++, k = max(k - 1, 0)) {

		if (group[i] == N - 1) continue;

		for (int j = SA[group[i] + 1]; S[i + k] == S[j + k]; k++);

		LCP[group[i]] = k;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	while (TC--) {
		cin >> S;
		SA.clear(), LCP.clear(); group.clear();

		N = S.size();
		SA.resize(N), LCP.resize(N); group.resize(N);

		getSA(); getLCP();
	
		int ret = LCP[0];
		
		for (int i = 1; i < N - 1; i++) {
			if (LCP[i] > LCP[i - 1]) {
				ret += LCP[i] - LCP[i - 1];
			}
		}
		cout << ret << endl;
	}
	return 0;
}