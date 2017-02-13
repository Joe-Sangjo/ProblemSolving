#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const string ok = "MAX PARTY SIZE IS ";
const string no = "CONTRADICTION AT ";


struct OptimizedDisjointSet{
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1){
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v){
		u = find(u); v = find(v);

		if(u == v) return;

		if(rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]++;
	}
};
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);
	while(TC--){
		int N, M;	scanf("%d %d", &N, &M);

		OptimizedDisjointSet op(N);
		string buf;
		bool check = false;
		int a, b;
		int setA, setB;
		for(int i = 1; i <= M; i++){
			cin>>buf; scanf("%d %d", &a, &b);
			if(buf =="ACK"){
				op.merge(a, b);
			}
			else{
				if(op.find(a) == op.find(b)){
					cout<<no<<i<<endl;
					check = true;
					break;
				}
				else{
					setA = a; setB = b;
				}
			}
		}
		if(check){
			continue;
		}

	}
	return 0;
}