#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 21000000000
using namespace std;
int n, m;
vector<vector<pair<int, int> > > adj;

int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);


	scanf("%d %d", &n, &m);
	// printf("%d %d \n",n, m);

	adj = vector<vector<pair<int, int> > >(n);
	int x, y, w;


	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &x, &y, &w);
		x--; y--;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}

	

	return 0;
}