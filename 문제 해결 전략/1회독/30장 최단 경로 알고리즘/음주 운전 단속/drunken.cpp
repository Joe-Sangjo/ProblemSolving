#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int v, e;
int adj[501][501];
int delayed[501];
const int INF = 0x3f3f3f3f;

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	memset(adj, INF, sizeof(adj));

	scanf("%d %d", &v, &e);

	for(int i = 0; i < v; i++) adj[i][i] = 0;

	int b1, b2, b3;
	for(int i = 0; i < v; i++){
		scanf("%d", &delayed[i]);
	}

	for(int i = 1; i < v; i++){
		delayed[i] = max(delayed[i], delayed[i - 1]);
	}

	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &b1, &b2, &b3);
		adj[b1 - 1][b2 - 1] = b3;
		adj[b2 - 1][b1 - 1] = b3;
	}

	for(int i = 0; i < v; i++)	adj[i][i] = 0;

	for(int k = 0; k < v; k++)
		for(int i = 0; i < v; i++)
			for(int j = 0; j < v; j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j] + delayed[k]);
			}

	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &b1, &b2);
		printf("%d\n",adj[b1-1][b2-1]);
	}
	return 0;
}