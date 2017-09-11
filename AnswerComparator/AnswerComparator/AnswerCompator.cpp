#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;



int main() {
	freopen("output.txt", "r", stdin);

	int testcase = 10;

	vector<int> ans1, ans2;
	for (int i = 0; i < testcase; i++) {
		int temp1; cin >> temp1;
		ans1.push_back(temp1);
	}
	for (int i = 0; i < testcase; i++) {
		int temp2; cin >> temp2;
		ans2.push_back(temp2);
	}
	for (int i = 0; i < testcase; i++) {
		if (ans1[i] != ans2[i]) {
			cout << i << "            " << endl;
		}
	}


	return 0;
}