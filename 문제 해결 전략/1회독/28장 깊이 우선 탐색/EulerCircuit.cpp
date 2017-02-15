#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
vector<vector<int> > adj;

void getEulerCirciut(int here, vector<int>& circiut){
	for(int there = 0; there < adj.size() ; there++){
		while(adj[here][there] > 0){
			adj[here][there]--;
			adj[there][here]--;
			getEulerCirciut(there, circiut);
		}
	}
	circiut.push_back(here);
}
int main(){







	return 0;
}