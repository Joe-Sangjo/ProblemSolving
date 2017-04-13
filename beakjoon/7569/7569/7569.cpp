#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

#define mp make_pair
using namespace std;
int M, N, H;

vector<vector<int> > tomato[101];


bool isIn(int h, int y, int x) {
	return h >= 0 && h < H && y >= 0 && y < N && x >= 0 && x < M;
}

int dy[6] = {0,0,0,0,1,-1};
int dx[6] = {0,0,1,-1,0,0};
int dh[6] = {1,-1,0,0,0,0};
int main() {
	freopen("input.txt", "r", stdin);

	cin >> M >> N >> H;


	vector<vector<int> > dist[101];

	for (int h = 0; h < H; h++) {
		dist[h] = vector<vector<int> >(N);
		for (int y = 0; y < N; y++) {
			dist[h][y] = vector<int>(M, -1);
		}
	}
	//h, y, x
	queue < pair<int, pair<int, int> > > q;
	for (int h = 0; h < H; h++) {
		vector<vector<int> > t = vector<vector<int> >(N);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				int temp; cin >> temp;
				t[y].push_back(temp);
				//익었으면,
				if (temp == 1) {
					dist[h][y][x] = 0;
					q.push(mp(h, mp(y, x)));
				}
			}
		}
		tomato[h] = t;
	}

	int ret = -1;

	while (!q.empty()) {
		int hereH = q.front().first;
		int hereY = q.front().second.first;
		int hereX = q.front().second.second;

		int hereDist = dist[hereH][hereY][hereX];

		q.pop();

		for (int i = 0; i < 6; i++) {
			int thereH = hereH + dh[i];
			int thereY = hereY + dy[i];
			int thereX = hereX + dx[i];
			if (isIn(thereH, thereY, thereX) && dist[thereH][thereY][thereX] == -1 && tomato[thereH][thereY][thereX] == 0) {
				dist[thereH][thereY][thereX] = hereDist + 1;
				q.push(mp(thereH, mp(thereY, thereX)));
			}
		}
	}

	bool check = true;
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (tomato[h][y][x] != -1) {
					if (dist[h][y][x] == -1) {
						check = false;
					}
					ret = max(ret, dist[h][y][x]);
				}
			}
		}
	}
	if (!check) {
		cout << -1 << endl;
		return 0;
	}
	cout << ret << endl;
		
	return 0;
}