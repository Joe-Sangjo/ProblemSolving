#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#define mp make_pair
using namespace std;

//������, �����۷���
int dist[100001];
int main() {
	freopen("input.txt", "r", stdin);

	int N, K, M;

	cin >> N >> K >> M;

	//cout << N << K << M;

	//first�� ����ȣ , second�� ������ȣ
	vector<vector<pair<int, int> > > adj = vector<vector<pair<int, int> > >(N);

	for (int i = 0; i < M; i++) {
		vector<int> temp;
		for (int j = 0; j < K; j++) {
			int t; cin >> t;
			temp.push_back(t - 1);
			//cout << t << " ";
		}
		//cout << endl;
		for (int j = 0; j < temp.size() - 1; j++) {
			int from = temp[j], to = temp[j + 1];
			adj[from].push_back(mp(to, i));
			adj[to].push_back(mp(from, i));
		}
	}



	 priority_queue<pair<int ,pair<int, int> > > q;
	 memset(dist, -1, sizeof(dist));

	 //1001�� �������� ����
	 dist[0] = 0;
	 q.push(mp(0, mp(0, 1001)));
	
	 while (!q.empty()) {
		 int here = q.top().second.first;
		 int hereLineNum = q.top().second.second;

		 int hereDist = -q.top().first;
		 q.pop();

		 if (hereDist > dist[here]) continue;

		 for (int i = 0; i < adj[here].size(); i++) {
			 int there = adj[here][i].first;
			 int thereLineNum = adj[here][i].second;

			 int nextDist = hereDist + (hereLineNum != thereLineNum);

			 if (dist[there] == -1 || dist[there] > nextDist) {
				 q.push(mp(-nextDist, mp(there, thereLineNum)));
				 dist[there] = nextDist;
			 }
		 }

	 }

	 cout << dist[N - 1] + 1<< endl;

	return 0;
}