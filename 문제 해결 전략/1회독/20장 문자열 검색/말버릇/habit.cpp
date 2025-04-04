#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int K;
string in;
class Comparator{
public:
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t){
		// group = _group;	t = _t;
	}
	bool operator () (int a, int b){
		if(group[a] != group[b]) return group[a] < group[b];

		return group[a + t] < group[b + t];
	}
};

int commonPrefix(const string& s, int i, int j);
int longestFrequent(int k, const string& s);
vector<int> getSuffixArray(const string& s);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	while(TC--){
		cin>>K>>in;
		// cout<<K<<"  "<<in<<endl;
		cout<<longestFrequent(K, in)<<endl;
	}





	return 0;
}

int commonPrefix(const string& s, int i, int j){
	int k = 0;
	while(i < s.size() && j < s.size() && s[i] == s[j]){
		i++;	j++;	k++;
	}
	return k;
}

int longestFrequent(int k, const string& s){
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for(int i = 0; i + k <= s.size(); i++){
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	}
	return ret;
}
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