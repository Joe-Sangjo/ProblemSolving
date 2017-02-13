#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > adj;

vector<int> discovered, finished;

int counter;


void dfs2(int here){

	discovered[here] = counter ++;

	for(int i = 0; i < adj[here].size(); i++){
		int there = adj[here][i];
		cout<<"(" << here <<" , " << there<<" ) is a ";

		if(discovered[there] == -1){
			cout<<"tree edge"<<endl;
			dfs2(there);
		}
		else if(discovered[here] < discovered[there])
			cout<<"forward edge"<<end;
		else if(finished[there] == 0)
			cout<<"back edge"<<endl;
		else
			cout<<"cross edge"<<endl;
	}
	finished[here] = 1;
}


int main(){



	return 0;
}