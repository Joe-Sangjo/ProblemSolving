#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;



vector<int> getPartialMatch(const string& N){
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while(begin + matched < m){
		if(N[begin + matched] == N[matched]){
			matched++;
			pi[begin + matched -1] = matched;
		}
		else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> naiveSearch(const string& H, const string& N){
	vector<int> ret;

	for(int begin = 0; begin + N.size() <= H.size(); begin++){
		bool matched = true;

		for(int i = 0; i < N.size(); i++){
			if(H[begin + 1] != N[i]){
				matched = false;
				break;
			}
		}
		if(matched) ret.push_back(begin);
	}
	return ret;
}


vector<int> kmpSearch(const string& H, const string& N){
	int n = H.size(), m = N.size();

	vector<int> ret;
	int begin = 0, matched = 0;


	vector<int> pi = getPartialMatch(N);
	while(begin <= n - m){
		if(matched < m && H[begin + matched] == N[matched] ){
			matched++;

			if(matched == m) ret.push_back(begin);
		}
		else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

vector<int> getPartialMatchNaive(const string& N){
	int m = N.size();

	vector<int> pi(m, 0);

	for(int begin = 1; begin < m; begin++){
		for(int i = 0; i + begin < m; i++){
			if(N[begin + i] != N[i])	break;

			pi[begin + i] = max(pi[begin + i], i + 1);
		}
	}
	return pi;
}


int main(){
	// freopen



	return 0;
}
