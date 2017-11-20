#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>


using namespace std;
int L;
string ad;
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> L >> ad;

	cout << L << " " << ad;
	return 0;    
}