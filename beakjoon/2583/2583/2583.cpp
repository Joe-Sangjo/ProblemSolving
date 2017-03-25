#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int m, n, k;
int x_[101], y_[101], x__[101], y__[101];

bool map[102][102];
bool visited[102][102];

queue<pair<int, int> > q;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
//안이면 true, 밖이면 false
bool isIn(int y, int x) {
	return y < m && y >= 0 && x < n && x >= 0;
}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> m >> n >> k;

	memset(map, true, sizeof(map));
	for (int i = 0; i < k; i++) {

		cin >> x_[i] >> y_[i] >> x__[i] >> y__[i];
		for (int y = y_[i]; y < y__[i]; y++) {
			for (int x = x_[i]; x < x__[i]; x++) {
				map[y][x] = false;
			}
		}
	}



	memset(visited, true, sizeof(visited));

	int ret = 0;;
	vector<int> size;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] && visited[y][x]) {


				ret++;
				int s = 0;
				q.push(make_pair(y, x));
				visited[y][x] = false;

				while (!q.empty()) {

					
					int hereY = q.front().first;
					int hereX = q.front().second;
					//cout << hereY << " " << hereX << endl;
					s++;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int thereY = hereY + dy[i];
						int thereX = hereX + dx[i];
						if (isIn(thereY, thereX) && map[thereY][thereX] && visited[thereY][thereX]) {
							visited[thereY][thereX] = false;
							q.push(make_pair(thereY, thereX));
						}
					}


				}
				size.push_back(s);
			}
		}
	}

	cout << ret << endl;
	sort(size.begin(), size.end());

	for (int i = 0; i < ret; i++) {
		cout << size[i] << " ";
	}
	cout << endl;

	return 0;
}
