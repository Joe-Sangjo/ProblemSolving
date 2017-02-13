#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N;

int bfs(const vector<int>& perm){
	int n = perm.size();

	vector<int> sorted = perm;
	sort(sorted.begin(), sorted.end());

	queue<vector<int> > q;
	map<vector<int>, int> distance;

	distance[perm] = 0;

	q.push(perm);
	while(!q.empty()){
		vector<int> here = q.front();
		q.pop();

		if(here == sorted) return distance[here];
		int cost = distance[here];

		for(int i = 0; i < n; i++)
			for(int j = i + 2; j <= n; j++){
				reverse(here.begin() + i, here.begin() + j);
				if(distance.count(here) == 0){
					distance[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}

	}
}

map<vector<int>, int> toSort;

void precalc(int n){
	// cout<<1<<endl;
	vector<int> perm(n);
	for(int i = 0; i < n; i++) perm[i] = i;

	queue<vector<int> > q;
	q.push(perm);

	toSort[perm] = 0;

	while(!q.empty()){
		// cout<<1<<endl;
		vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		// cout<<1<<endl;
		for(int i = 0; i < n; i++){
			// cout<<1<<endl;
			for(int j = i + 2; j <= n; j++){
				reverse(here.begin() + i, here.begin() + j);
				if(toSort.count(here) == 0){
					toSort[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
		// cout<<1<<endl;
	}
}
int solve(const vector<int>& perm){

	int n = perm.size();
	vector<int> fixed(n);

	for(int i = 0; i < n; i++){
		int smaller = 0; 
		for(int j = 0; j < n; j++)
			if(perm[j] < perm[i])
				smaller++;
		fixed[i] = smaller;
	}
	return toSort[fixed];
}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);

	while(TC--){
		scanf("%d", &N);
		vector<int> perm(N);
		for(int i = 0; i < N; i++){
			scanf("%d", &perm[i]);
		}
		// printf("%d\n", bfs(perm));
		precalc(N);
		printf("%d\n", solve(perm));
	}



	return 0;
}