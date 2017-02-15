#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

int n;
deque<int> leng;
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	int a;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n;
		leng.clear();
		for(int i = 0 ; i < n; i++){
			cin>>a; leng.push_back(a);
		}
		int min_cost = 0;
		// for(deque<int>::iterator itr = leng.begin() ; itr != leng.end(); itr++){
		// 	cout<<*itr<<" ";
		// }
		// cout<<endl;
		deque<int>::iterator itr;
		while(leng.size() != 1){
			sort(leng.begin(), leng.end());
			itr = leng.begin();
			min_cost += leng[0] + leng[1];
			leng[1] += leng[0]; 
			leng.pop_front();
		}
		cout<<min_cost<<endl;
	}

	return 0;
}

