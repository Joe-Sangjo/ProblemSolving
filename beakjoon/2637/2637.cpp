#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, m;


vector<vector<pair<int, int> > > toy;


int ans[101];

void dfs(int here){


	//기본 부품일 경우.
	if(toy[here].size() == 0){
		return;
	}

	int nowNum = ans[here];
	ans[here] = 0;
	for(int i = 0; i < toy[here].size(); i++){
		int there = toy[here][i].first;
		int num = toy[here][i].second;

		ans[there] += nowNum * num;

		dfs(there);
	}
}


int main(){
	freopen("input.txt","r",stdin);

	cin>>n>>m;
	memset(ans, 0, sizeof(ans));

	toy = vector<vector<pair<int, int> > >(n);
	for(int i = 0; i < m; i++){
		int x, y, k;
		cin>>x>>y>>k;

		toy[x - 1].push_back(make_pair(y - 1, k));
	}

	//n - 1이 마지막임.
	ans[n - 1] = 1;
	dfs(n - 1);

	for(int i = 0; i < n; i++){
		if(ans[i] != 0){
			cout<<i + 1 <<" "<<ans[i]<<endl;
		}
	}



	return 0;
}