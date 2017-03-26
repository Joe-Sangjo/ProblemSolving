#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> topoSort;

bool isVisited[1005];
bool finish[1005];
bool check = true;
void dfs(int here){
	if(!check) return;
	isVisited[here] = true;

	for(int i = 0; i < adj[here].size(); i++){

		int there = adj[here][i];
		if(!isVisited[there]){
			dfs(there);
		}
		else if(!finish[there]){
			check = false;
			return;
		}
	}

	topoSort.push_back(here);
	finish[here] = true;
}
int main(){
	freopen("input.txt","r",stdin);

	cin>>n>>m;
	memset(isVisited, false, sizeof(isVisited));
	memset(finish, false, sizeof(finish));


	adj = vector<vector<int> >(n);
	for(int i = 0; i < m; i++){
		int temp;
		cin>>temp;
		vector<int> hoi;
		while(temp--){
			int t; cin>>t; hoi.push_back(t - 1);
		}

		for(int j = 0; j < hoi.size() - 1; j++){
			int here = hoi[j]; int there = hoi[j + 1]; 
			adj[here].push_back(there);
		}
	}


	for(int i = 0; i < n; i++){
		if(!isVisited[i])
			dfs(i);
	}

	if(!check){
		cout<<0<<endl;
		return 0;
	}
	reverse(topoSort.begin(), topoSort.end());

	for(int i = 0; i <topoSort.size(); i++){
		cout<<topoSort[i] + 1<<endl;
	}


	return 0;
}