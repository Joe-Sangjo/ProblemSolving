#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


class SuffixComparator{
public:
	const string& s;
	SuffixComparator(const string& s) : s(s){}
	bool operator() (int i, int j){
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
	}
};

vector<int> getSuffixArrayNaive(const string & s){
	vector<int> perm;
	for(int i = 0; i < s.size(); i++) perm.push_back(i);

	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm;
}
class Comparator{
public:
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t){

	}
	bool operator () (int a, int b){
		if(group[a] != group[b]) return group[a] < group[b];

		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray(const string& s){
	int n = s.size();

	int t = 1;
	vector<int> group(n + 1);

	for(int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1;

	
	vector<int> perm(n);
	for(int i = 0; i < n ; i++) perm[i] = i;

	while(t < n) {
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);

		t *= 2;

		if(t >= n) break;

		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for(int i = 1; 1 < n; i++){
			if(compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup;
	}
	return perm;
}
int main(){
	// freopen("input.txt","r",stdin);
	// setbuf(stdout, NULL);









	return 0;
}

