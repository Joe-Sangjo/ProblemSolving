#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int NINF = -0x3f3f3f3f;
int n, m;
vector<vector<pair<int, int> > > adj;

vector<int> bellmanfordforlongest(int src){
	vector<int> lower(n, NINF);

	lower[src] = 0;

	for(int iter = 0; iter < n - 1; iter++){
		for(int here = 0; here < n; here++){
			for(int i = 0; i < adj[here].size(); i++){
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				lower[there] = max(lower[there], lower[here] + cost);
			}
		}
	}
	return lower;
}
vector<int> dijkstraforlongest(int src){
	
	vector<int> dist(n, NINF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while(!pq.empty()){

		int cost = pq.top().first;
		int here = pq.top().second;

		pq.pop();
		if(dist[here] > cost) continue;
		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;
			if(dist[there] < nextDist){
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}

	}
	return dist;
}
int main(){
	freopen("i.txt","r",stdin);
	setbuf(stdout, NULL);


	scanf("%d %d", &n, &m);
	adj = vector<vector<pair<int, int> > >(n);

	for(int i = 0; i < m; i++){
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back(make_pair(to, cost));
	}

	vector<int> ret = bellmanfordforlongest(0);
	for(int i = 0; i <ret.size(); i++){
		printf("%d ", ret[i]);
	}
	printf("\n");
	ret = dijkstraforlongest(0);
	for(int i = 0; i < ret.size(); i++){
		printf("%d ", ret[i]);
	}
	printf("\n");
	return 0;
}