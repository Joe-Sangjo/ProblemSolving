#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct FenwickTree{
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1){}


	int sum(int pos){
		pos++;
		int ret = 0;
		while(pos > 0){
			ret += tree[pos];
			pos &= (pos - 1);
		}

		return ret;
	}

	void add(int pos, int val){
		pos++;
		while(pos < tree.size()){
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}

};

long long countMoves(const vector<int>& A);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	scanf("%d", &TC);
	while(TC--){
		int N, buf;
		scanf("%d", &N);
		vector<int> A(N);

		for(int i = 0; i < N; i++){
			scanf("%d",&A[i]);
			// cout<<A[i]<<" ";
		}

		printf("%lld\n", countMoves(A));

	}

	return 0;
}

long long countMoves(const vector<int>& A){
	FenwickTree tree(1000000);
	long long ret = 0;
	for(int i = 0; i < A.size(); i++){

		ret += tree.sum(999999) - tree.sum(A[i]);
		tree.add(A[i],1);
	}
	return ret;

}