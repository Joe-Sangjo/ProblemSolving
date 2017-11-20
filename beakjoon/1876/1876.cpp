#include <iostream>
#include <cstdio>
#include <vector>
#include <string>


using namespace std;

vector<int> getPartialMatch(string N) {

	int m = N.size();
	vector<int> pi;
	int matched = 0;

	for (int i = 1; i < m; i++) {
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		if (N[i] == N[matched])
			pi[i] = ++matched;
	}
	return pi;
}
//
//vector<int> kmp(string H, string N) {
//
//	int n = H.size(), m = N.size();
//	vector<int> ret;
//	vector<int> pi = getPartialMatch(N);
//	int matched = 0;
//
//	for (int i = 0; i < n; i++) {
//		while (matched > 0 && H[i] != N[matched])
//			matched = pi[matched - 1];
//		if (H[i] == N[matched - 1]) {
//			matched++;
//			if (matched == m) {
//				ret.push_back(i - m + 1);
//				matched = pi[matched - 1];
//			}
//		}
//		
//	}
//
//}


int main() {

	cout << 1 << endl;



	return 0;
}