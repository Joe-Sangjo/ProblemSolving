#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define mp make_pair
using namespace std;
int N, E;
int value[20001];
vector<vector<pair<int, int> > > adj;
int dp[20001]; int path[20001];

int solve(int here) {
	//cout << here << endl;
	if (adj[here].size() == 0) return value[here];

	int& ret = dp[here];

	if (ret != -1) return ret;

	int next;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i].first;
		int cost = adj[here][i].second;

		int nextGain = solve(there) - cost;
		if (ret < nextGain) {
			ret = nextGain;
			next = there;
		}
	}
	path[here] = next;
	return ret += value[here];

}
void reconstruct(int here, vector<int>& visit) {
	visit.push_back(here);
	if (path[here] == -1) return;
	int there = path[here];
	reconstruct(there, visit);
}
int main() {
	freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	//항상 0번에서 출발.

	while (TC--) {
		memset(value, -1, sizeof(value)); memset(dp, -1, sizeof(dp)); memset(path, -1, sizeof(path));
		 adj.clear(); 
		cin >> N >> E;
		for (int i = 0; i < N; i++) {
			cin >> value[i];
		}
		//first는 to, second는 cost
		adj = vector<vector<pair<int, int> > >(N);
		for (int i = 0; i < E; i++) {
			int from, to, cost; cin >> from >> to >> cost;
			from--, to--;
			adj[from].push_back(mp(to, cost));
		}
		
		int ret = solve(0);
		cout << ret << " ";
		vector<int> visit;
		reconstruct(0, visit);
		cout << visit.size() << endl;
		for (int i = 0; i < visit.size(); i++) {
			cout << visit[i] + 1 << " ";
		}
		cout << endl;
	}





	return 0;
}