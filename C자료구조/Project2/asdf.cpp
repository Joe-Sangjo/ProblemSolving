#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("output.txt", "w", stdout);
	vector<int> a;

	for (int i = 0; i < 100; i++) {
		a.push_back(i);
	}
	sort(a.begin(), a.end());


	for (int i = 0; i < 100; i++) {
		cout << a[i] << " ";
	}

}