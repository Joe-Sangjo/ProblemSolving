#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

int N;
vector<int> russian;
vector<int> korean;
int order(const vector<int>& russian, const vector<int>& korean);
int main(){

	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	int a, b;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N;
		russian.clear(); korean.clear();
		for(int i = 0 ; i < N; i++){
			cin>>a; russian.push_back(a);
		}

		for(int i = 0; i < N; i++){
			cin>>a; korean.push_back(a);
		}
		cout<<order(russian,korean)<<endl;

	}




	return 0;
}

int order(const vector<int>& russian, const vector<int>& korean){
	int n = russian.size(), wins = 0;

	multiset<int> ratings(korean.begin(), korean.end());

	for(set<int>::iterator itr = ratings.begin(); itr!=ratings.end(); itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
	for(int rus = 0; rus < N; rus++){

		if(*ratings.rbegin() < russian[rus])
			ratings.erase(ratings.begin());
		else{
			ratings.erase(ratings.lower_bound(russian[rus]));
			wins ++;
		}
	}
	return wins;
}