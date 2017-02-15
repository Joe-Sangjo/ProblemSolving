#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int v, e, t;
int adj[501][501];
int delay[501];
int W[500][500];

void solve(){
	vector<pair<int, int> > order;
	for(int i = 0; i < v; i++)
		order.push_back(make_pair(delay[i], i));

	sort(order.begin(), order.end());
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			if(i == j)
				W[i][j] = 0;
			else
				W[i][j] = adj[i][j];
		}
	}

	for(int k = 0; k < v; k++){
		int w = order[k].second;
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
				W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
			}
		}
	}

}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	scanf("%d %d", &v, &e);
	memset(adj, INF, sizeof(adj));

	int b1, b2, b3;

	for(int i = 0; i < v; i ++){
		scanf("%d", &delay[i]);
	}

	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &b1, &b2, &b3);
		adj[b1 - 1][b2 - 1] = b3;
		adj[b2 - 1][b1 - 1] = b3;
	}


	solve();


	scanf("%d", &t);

	int s, z;
	for(int i = 0; i < t; i++){
		scanf("%d %d", &s, &z);
		printf("%d\n",W[s-1][z-1] );
	}


	return 0;
}