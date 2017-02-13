#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, x[101], y[101], r[101];

class treenode{
public:
	int index;
	vector<treenode*> children;
	treenode(int in) : index(in){};
};




bool isin(int outer, int inner){
	return ((x[outer] - x[inner])*(x[outer] - x[inner]) 
	+ (y[outer] - y[inner]) * (y[outer] - y[inner]) 
	< (r[outer] - r[inner]) * (r[outer] - r[inner])) && r[outer] > r[inner];
}

bool ischild(int outer, int inner){
	if(!isin(outer, inner)) return false;

	vector<int> outofinner;

	for(int i = 0 ; i < N ; i++){
		if(i == outer && i == inner)	continue;

		if(isin(i, inner)){
			outofinner.push_back(i);
		}
	}

	// if(outofinner.empty()) return true;

	int n = outofinner.size();
	for(int i = 0 ; i < n; i++){

		if(!isin(outofinner[i],outer)){

			return false;

		}

	}

	return true;

}

treenode* maketree(int root){
	treenode* newtree = new treenode(root);
	for(int i = 0; i < N; i++){
		if(ischild(root, i)){
			newtree -> children.push_back(maketree(i));
		}
	}
	return newtree;
}
int MAX = 0;
int maxdist(treenode* root, int h){
	int n = root-> children.size();
	// int hhh = 0;
	vector<int> hhh;
	for(int i = 0 ; i < n; i ++){
		hhh.push_back(maxdist(children[i], h + 1));
	}
	sort(hhh.begin(), hhh.end());
	MAX = max(MAX, hhh[hhh.size() - 1] + hhh[hhh.size() - 2]);
	return h;
}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;
	while(TC--){
		cin>>N;
		for(int i = 0 ; i < N; i++){
			cin>>x[i]>>y[i]>>r[i];
		}

		treenode* root = maketree(0);

		// cout<<root->children[0]->index<<endl;
		maxdist(root, 0);
		cout<<MAX<<endl;
	}

	return 0;

}

int adder(int a, int b){
	return adder(a, b);
}