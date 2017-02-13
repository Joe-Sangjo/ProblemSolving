#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int NEGINF = -0x3f3f3f3f;


int g, w;
vector<vector<pair<int, int> > > adj;
vector<vector<int> > reachable;

int bellman2(int src, int target){
	vector<int> upper(g, INF);
	upper[src] = 0;

	for(int iter = 0; iter < g - 1; iter++){
		for(int here = 0; here < g; here++){
			for(int i = 0; i < adj[here].size(); i++){
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				upper[there] = min(upper[there], upper[here] + cost);
			}
		}
	}

	for(int here = 0; here < g; here++){
		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int cost = adj[here][i].second;

			if(upper[here] + cost <upper[there])
				if(reachable[src][here] && reachable[here][target]){
					return NEGINF;
				}
		}
	}
	return upper[target];
}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &g, &w);
		adj = vector<vector<pair<int, int> > >(g);
		reachable = vector<vector<int> >(g, vector<int>(g,false));
		int a, b, c;
		for(int i = 0; i < w; i++){
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			reachable[a][b] = true;
		}
		int ret = bellman2(0, 1);

		for(int i = 0; i < g; i++){
			for(int j = 0; j < adj[i].size(); j++){
				adj[i][j].second *= -1;
			}
		}
		int ret2 = bellman2(0, 1);
		if(ret >= INF || ret2 >= INF){
			printf("%s\n","UNREACHABLE" );
		}
		else if(ret <= NEGINF || ret2 <= NEGINF){
			ret <= NEGINF ? printf("INFINITY ") : printf("%d ", ret);
			ret2 <= NEGINF ? printf("INFINITY\n") : printf("%d\n",-ret2 );
		}
		else
			printf("%d %d\n", ret, -ret2);

	}
	return 0;
}