#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
const int INF = 0x3f3f3f3f;
int v;
vector<pair<int, int> > adj[410];

const int START = 401;

int vertex(int delta){
	return delta + 200;
}

vector<int> dijkstra(int src){
	vector<int> dist(v, INF);
	dist[src] = 0;

	priority_queue<pair<int,int> > pq;

	

}

int solve(const vector<int>&a, const vector<int>& b){

	v = 402;
	for(int i = 0; i < v; i++)	adj[i].clear();

	for(int i = 0; i < a.size(); i++){
		int delta = a[i] - b[i];
		adj[START].push_back(make_pair(vertex(delta), a[i]));
	}

	for(int delta = -200; delta <= 200; delta++){
		for(int i = 0; i < a.size(); i++){
			int next = delta + a[i] - b[i];

			if(abs(next) > 200) continue;
			adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
		}
	}

	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];

	if(ret == INF) return -1;
	return ret;
}



int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);


	int TC;	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &v);


	}

	return 0;
}