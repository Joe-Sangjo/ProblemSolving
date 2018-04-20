#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

class DSet {
private:
	vector<int> rank;
	vector<int> parent;
public:
	DSet(int n) : parent(n) , rank(n, 1){
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (this->parent[u] == u) return u;
		return this->parent[u] = find(u);
	}

	void merge(int u, int v) {
		u = find(u); v = find(v);

		if (u == v) return;
		if (this->rank[u] > this->rank[v]) swap(u, v);
		
		this->parent[u] = v;
		if (this->rank[u] == this->rank[v]) this->rank[v]++;
	}
};

int main() {

	freopen("input.txt", "r", stdin);
	freopen("out[put.txt", "w", stdout);
	int n, m;

	scanf("%d%d", &n, &m);
	n++;

	DSet *ds = new DSet(n + 1);


	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		//ÇÕÄ£´Ù
		if (cmd == 0) {
			printf("%d %d\n", a, b);
			ds->merge(a, b);
		}
		else {
			if (ds->find(a) == ds->find(b))	printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}