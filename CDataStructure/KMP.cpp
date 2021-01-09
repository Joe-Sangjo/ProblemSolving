#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;


vector<int> getPi(const string& N){
	int m = N.size();
	int matched = 0;

	vector<int> pi(m, 0);
	for(int i = 1; i < m; i++){
		while(matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		if(N[i] == N[matched])
			pi[i] = ++matched;
	}
	return pi;
}
vector<int> kmp(const string& H, const string& N){

	int n = H.size(), m = N.size();

	int matched = 0;
	vector<int> pi = getPi(N);

	vector<int> ret;

	for(int i = 0; i < n; i++){
		while(matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];

		if(H[i] == N[matched]){
			matched++;
			if(matched == m){
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main(){

	string H, N;

	getline(cin, H); getline(cin, N);

	vector<int> k = kmp(H, N);
    
	cout<<k.size()<<endl;
	for(int i = 0; i < k.size(); i++){
		printf("%d ", k[i] + 1);
	}
	return 0;
}
