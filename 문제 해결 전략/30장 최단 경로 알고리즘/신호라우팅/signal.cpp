#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
const double INF = numeric_limits<double>::max();

vector<vector<pair<int, double> > > adj;

int n, m;

vector<double> dijkstra(int src){

	vector<double> dist(n, INF);

	dist[src] = 1.0;

	priority_queue<pair<int , double> > pq;

	pq.push(make_pair(src, -1.0));
	while(!pq.empty()){
		int here = pq.top().first;
		double cost = -pq.top().second;

		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;

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

	int TC;	scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &n, &m);
		adj = vector<vector<pair<int, double> > >(n);
		for(int i = 0; i < m; i++){
			int from, to; double c;
			scanf("%d %d %lf", &from, &to, &c);
			adj[from].push_back(make_pair(to, c));
			adj[to].push_back(make_pair(from,c));
		}
		vector<double> d = dijkstra(0);
		printf("%.10f\n", d[n-1]);
	}

	return 0;
}