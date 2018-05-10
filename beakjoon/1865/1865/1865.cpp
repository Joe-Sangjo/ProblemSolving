#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M, W;
#define INF 0x3f3f3f3f

int main() {

	freopen("input.txt", "r", stdin);


	int TC; scanf("%d", &TC);
	while (TC--) {

		scanf("%d%d%d", &N, &M, &W);
		vector<pair<int, int> > adj[510];

		for (int i = 0; i < M; i++) {
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back(make_pair(e, t));
			adj[e].push_back(make_pair(s, t));
		}

		for (int i = 0; i < W; i++) {
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back(make_pair(e, -t));

		}
		vector<int> upper(N + 1, INF);

		upper[1] = 0;
		bool updated;
		for (int iter = 0; iter < N; iter++) {
			updated = false;
			for (int here = 1; here <= N; here++) {
				for (int j = 0; j < adj[here].size(); j++) {
					int there = adj[here][j].first;
					int cost = adj[here][j].second;
					if (upper[there] > upper[here] + cost) {
						upper[there] = upper[here] + cost;
						updated = true;
					}
				}
			}
			if (!updated) break;
		}
		if (updated) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}