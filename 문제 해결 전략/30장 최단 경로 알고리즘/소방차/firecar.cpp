#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int v, e, n, m;

vector<vector<pair<int, int> > > adj;

vector<int> dijkstra(int src){

	vector<int> dist(v + 1,INF);

	dist[src] = 0;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(src, 0));

	while(!pq.empty()){

		int here = pq.top().first;
		int cost = -pq.top().second;

		pq.pop();

		if(dist[here] < cost)		continue;

		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if(dist[there] > nextDist){
				dist[there] = nextDist;
				pq.push(make_pair(there, -nextDist));
			}
		}
	}
	return dist;
}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);

	while(TC--){
		scanf("%d %d %d %d", &v, &e, &n, &m);
		adj = vector<vector<pair<int, int> > >(v + 1);

		for(int i = 0; i < e ; i++){
			int a, b, t;
			scanf("%d %d %d", &a, &b, &t);
			adj[a].push_back(make_pair(b,t));
			adj[b].push_back(make_pair(a,t));
		}

		vector<int> fire;

		for(int i = 0 ; i < n ; i++){
			int a; scanf("%d", &a);
			fire.push_back(a);
		}
		for(int i = 0; i < m ; i++){
			int a; scanf("%d", &a);
			adj[0].push_back(make_pair(a, 0));
		}
		vector<int> ret = dijkstra(0);
		int sum = 0;
		for(int i = 0; i < fire.size(); i++){
			sum += ret[fire[i]];
		}
		printf("%d\n",sum);
	}
	return 0;
}