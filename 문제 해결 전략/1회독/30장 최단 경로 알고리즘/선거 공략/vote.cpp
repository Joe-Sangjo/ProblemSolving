#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
const int INF = 0x3f3f3f3f;

int v, m, n;
int adj[201][201];

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	while(T--){
		memset(adj, INF, sizeof(adj));

		scanf("%d %d %d", &v, &m, &n);
		int b1,b2,b3;
		for(int i = 0; i < v; i++) adj[i][i] = 0;

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &b1, &b2, &b3);
			adj[b1][b2] = b3;	adj[b2][b1] = b3;
		}

		for(int k = 0; k < v;  k++){
			for(int i = 0; i < v; i++){
				for(int j = 0; j < v; j++){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

		int num = 0;

		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &b1, &b2, &b3);
			// printf("%d  %d\n", adj[b1][b2],b3);
			if(adj[b1][b2] <= b3){
				num++;	
			}
			else{
				adj[b1][b2] = min(adj[b1][b2], b3);
				adj[b2][b1] = min(adj[b2][b1], b3);
				for(int i = 0; i < v; i++){
					for(int j = 0; j < v; j++){
						adj[i][j] = min(adj[i][j], adj[i][b1] + adj[b1][j]);
					}
				}
			}
			// for(int i = 0; i < v; i++){
			// 	for(int j = 0; j < v; j++){
			// 		adj[i][j] = min(adj[i][j], adj[i][b2] + adj[b2][j]);
			// 	}
			// }
		}
		printf("%d\n",num );
	}

	return 0;
}