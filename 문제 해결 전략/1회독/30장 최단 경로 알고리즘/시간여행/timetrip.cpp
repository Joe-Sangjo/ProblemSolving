#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int NEGINF = -INF;
const int M = 1000000;
int v, w;
vector<vector<pair<int, int> > > adj;
vector<int> upper;
vector<int> lower;
void bellmanFord(int src){

	upper[src] = 0;	lower[src] = 0;
	bool updated;
	bool updated2;
	for(int iter = 0; iter < v; iter++){
		updated = false;
		updated2 = false;
		for(int here = 0; here < v; here++){
			for(int i = 0; i < adj[here].size(); i++){
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if(upper[there] > upper[here] + cost){
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if(!updated) break;
	}

	if(updated) upper.clear();
	for(int iter = 0; iter < v; iter++){
		updated2 = false;
		for(int here = 0; here < v; here++){
			for(int i = 0; i < adj[here].size(); i++){
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if(lower[there] < lower[here] + cost){
					lower[there] = lower[here] + cost;
					updated2 = true;
				}
			}
		}
		if(!updated2) break;
	}
	if(updated2) lower.clear();
}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &v, &w);
		adj = vector<vector<pair<int, int> > >(v);
		upper = vector<int>(v, INF);
		lower = vector<int>(v, NEGINF);
		int a, b, d;
		for(int i = 0; i < w; i++){
			scanf("%d %d %d", &a, &b, &d);
			adj[a].push_back(make_pair(b, d));
		}
		
		bellmanFord(0);
		if(upper.size() == 0 || lower.size() == 0){
			printf("%s\n", "UNREACHABLE");

		}
		else{
			if(upper[1] >= INF){
				printf("%s ", "INFINITY");
			}
			else{
				printf("%d ", upper[1]);
			}
			if(lower[1] <= NEGINF){
				printf("%s\n","INFINITY" );
			}
			else{
				printf("%d\n", lower[1]);
			}
		}
		// if(upper.size() == 0 || lower.size() == 0){
		// 	if(upper.size() == 0){
		// 		printf("INFINITY ");
		// 	}
		// 	else{
		// 		printf("%d ", upper[1]);
		// 	}
		// 	if(lower.size() == 0){
		// 		printf("INFINITY\n");
		// 	}
		// 	else{
		// 		printf("%d\n", lower[1] );
		// 	}
		// 	continue;
		// }
		// if(upper[1] >= INF - M|| lower[1] <= NEGINF + M){
		// 	printf("UNREACHABLE\n");
		// 	continue;
		// }
	}

	return 0;
}