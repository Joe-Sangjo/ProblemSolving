#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> dist;

void dfs(int here) {
	dist[here] = true;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!dist[there])
			dfs(there);
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	adj = vector<vector<int> >(n);
	for (int i = 0; i < n; i++) {
		adj[i] = vector<int>(n);

	}
	dist = vector<bool>(n, false);

	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		temp1--, temp2--;
		adj[temp1].push_back(temp2); adj[temp2].push_back(temp1);
	}

	int com = 0;
	for (int i = 0; i < n; i++) {
		if (!dist[i]) {
			com++;
			dfs(i);
		}
	}

	cout << com << endl;
	return 0;
}