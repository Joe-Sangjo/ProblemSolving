#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int partialMatchTable(string &S) {

	int m = S.size(), matched = 0;

	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {

		while (matched > 0 && S[i] != S[matched])
			matched = pi[matched - 1];

		if (S[i] == S[matched])
			pi[i] = ++matched;
	}
	return pi[m - 1];
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string S;
	while (cin >> S && S != ".") {

		int n = S.size();
		cout << n / (n - partialMatchTable(S)) << endl;

	}
	return 0;
}