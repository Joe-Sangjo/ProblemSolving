#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> T;
vector<int> F;
int main() {
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	T.resize(n); F.resize(m);

	for (int i = 0; i < n; i++)
		cin >> T[i];

	for (int i = 0; i < m; i++)
		cin >> F[i];








	return 0;
}