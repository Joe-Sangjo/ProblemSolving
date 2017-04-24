#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define mp make_pair
using namespace std;
int n, m;
int map[18][18];

int CoordinateToNumber(int y, int x) {
	return y * m + x;
}
pair<int, int> NumberToCoordinate(int num) {
	return mp(num / m, num % m);
}
int dy[4] = {0,0, 1 ,-1};
int dx[4] = {1, -1,0,0};
int ret;
int ZeroNum;
vector<pair<int, int> > virus;

bool isIn(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}
void solve(int num, vector<int>& wall) {
	//cout << num << endl;
	if (wall.size() == 3) {
		int dist[18][18];
		queue<pair<int, int> > q;
		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < 3; i++) {
			map[NumberToCoordinate(wall[i]).first][NumberToCoordinate(wall[i]).second] = 1;
		}
		int virusNum = virus.size();
		for (int i = 0; i < virus.size(); i++) {
			q.push(virus[i]);
			dist[virus[i].first][virus[i].second] = 0;
		}

		/*for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cout << map[y][x] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		while (!q.empty()) {

			int hereY = q.front().first; int hereX = q.front().second;
			int hereDist = dist[hereY][hereX];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int thereY = hereY + dy[i], thereX = hereX + dx[i];
				int nextDist = hereDist + 1;
				if (isIn(thereY, thereX)&& map[thereY][thereX] == 0 && dist[thereY][thereX] == -1) {
					q.push(mp(thereY, thereX));
					dist[thereY][thereX] = nextDist + 1;
					virusNum++;
				}
			}
		}

		int r = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (dist[y][x] == -1 && map[y][x] == 0) {
					r++;
				}
			}
		}
		
		ret = max(ret, r);
		for (int i = 0; i < 3; i++) {
				map[NumberToCoordinate(wall[i]).first][NumberToCoordinate(wall[i]).second] = 0;
		}

		return;
	}


	for (int next = num + 1; next < n * m; next++) {
		if (map[NumberToCoordinate(next).first][NumberToCoordinate(next).second] == 0) {
			wall.push_back(next);
			solve(next, wall);
			wall.pop_back();
		}
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	ZeroNum = 0;
	//cout << n << " " << m << endl;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				virus.push_back(mp(y, x));
			}
			else if (map[y][x] == 0) {
				ZeroNum++;
			}
			//cout << map[y][x] << " ";
		}
		//cout << endl;
	}
	ret = 0;
	vector<int> wall;
	for (int i = 0; i < n * m; i++) {
		if (map[NumberToCoordinate(i).first][NumberToCoordinate(i).second] == 0) {
			wall.push_back(i);
			solve(i, wall);
			wall.pop_back();
		}
	}
	cout << ret << endl;
	return 0;
}