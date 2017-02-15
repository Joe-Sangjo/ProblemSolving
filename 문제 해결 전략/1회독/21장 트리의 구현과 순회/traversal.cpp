#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> slice(const vector<int>& v, int a, int b){
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int> & inorder){

	const int N = preorder.size();

	if(preorder.empty()) return;

	const int root = preorder[0];

	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	const int R = N - 1 - L;

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout<<root<<" ";
}

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	while(TC--){
		cin>>N;
		int buf;
		vector<int> pre, inorder;
		for(int i = 0; i < N; i++){
			cin>>buf;
			pre.push_back(buf);
			// cout<<pre[i]<<" ";
		}
		// cout<<endl;
		for(int i = 0; i < N; i++){
			cin>>buf;
			inorder.push_back(buf);
		}
		printPostOrder(pre, inorder);
		cout<<endl;
	}
	return 0;
}