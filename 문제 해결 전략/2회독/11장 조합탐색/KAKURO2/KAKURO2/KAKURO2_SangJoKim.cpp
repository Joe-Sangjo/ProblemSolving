#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int n, q;

vector<vector<int> > board;

int main() {
	freopen("input.txt", "r", stdin);

	int TC; cin >> TC;

	while (TC--) {

		cin >> n;
		board.resize(n);
		for (int i = 0; i < n; i++) {
			board[i].resize(n);
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}








	}




	return 0;
}