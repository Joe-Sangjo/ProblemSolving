#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int v;

vector<vector<pair<int, int> > > adj;
vector<bool> visited;

int maxLength, lastNode;

void dfs(int here, int hereLength) {

	visited[here] = true;

	if (hereLength > maxLength) {
		maxLength = hereLength;
		lastNode = here;
	}

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i].first;
		int thereWeight = adj[here][i].second;

		if (!visited[there]) {
			dfs(there, hereLength + thereWeight);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &v);
	adj = vector<vector<pair<int, int> > >(v);
	for (int i = 0; i < v; i++) {
		int here; scanf("%d", &here);
		here--;
		int there, weight;
		while (scanf("%d", &there) && there != -1) {
			scanf("%d", &weight);
			there--;
			adj[here].push_back(make_pair(there, weight));
		}
	}
	maxLength = 0;

	visited = vector<bool>(v, false);

	dfs(0, 0);


	maxLength = 0;
	visited = vector<bool>(v, false);
	dfs(lastNode, 0);
	cout << maxLength << endl;
	return 0;
}