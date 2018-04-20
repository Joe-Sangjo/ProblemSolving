#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string longest(string s) {
	if (s.size() == 1) return s;
	int retLength = 1; int retI = 0; int retJ = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++) {
			if (s[i] == s[j]) {
				int a = i + 1, b = j - 1;
				bool check = true;
				while (a < b) {
					if (s[a] != s[b]) {
						check = false;
						break;
					}
					a++; b--;
				}
				if (check && retLength < j - i + 1) {
					retLength = j - i + 1;
					retI = i;
					retJ = j;
				}
			}
		}
	}
	return s.substr(retI, retLength);
}

int main() {

	string s = "abcda";
	cout << longest(s) << endl;
	return 0;
}