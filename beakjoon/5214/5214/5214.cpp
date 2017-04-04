#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;

//adj[n][i].first는 n과 연결되는 도시,
//adj[n][i].second는 n과 연결하는 도시가 사용하는 하이퍼루프 호선
vector<vector<pair<int, int> > > adj;


int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> n >> k >> m;
	
	adj = vector<vector<pair<int, int > > >(n+ 10);

	for (int i = 0; i < m; i++) {
		vector<int> link;
		for (int j = 0; j < k; j++) {
			int temp; cin >> temp;
			link.push_back(temp);
		}
		if (k == 1) continue;
		for (int j = 0; j < link.size() - 1; j++) {
			int from = link[j], to = link[j + 1];

			adj[from].push_back(make_pair(to, i));
			adj[to].push_back(make_pair(from, i));
		}
	}

	vector<int> dist(n + 10, 0x3f3f3f3f);

	//-fist는 cost, second.first는 역, second.second는 하이퍼튜브 몇 호선
	priority_queue<pair<int, pair<int, int> > > pq;

	//-1호선이라는 것은 상징적인 것.
	pq.push(make_pair(0, make_pair(1, -1)));
	dist[1] = 0;

	while (!pq.empty()) {

		int cost = -pq.top().first;
		int here = pq.top().second.first;
		int hereLineNum = pq.top().second.second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int thereLineNum = adj[here][i].second;
			int nextDist = cost + (hereLineNum != thereLineNum);

			if (dist[there] > nextDist) {
				pq.push(make_pair(-nextDist, make_pair(there, thereLineNum)));
				dist[there] = nextDist;
			}
		}
	}
	if (dist[n] >= 0x3f3f0000) {
		cout << -1 << endl;
	}
	else {
		cout << dist[n] + 1 << endl;
	}
	return 0;
}
