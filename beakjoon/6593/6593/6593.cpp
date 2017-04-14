#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#define mp make_pair
using namespace std;
int L, R, C;

int dist[31][31][31];

vector<string> board[31];

bool isIn(int h, int y, int x) {
	return h >= 0 && h < L && y >= 0 && y < R && x >= 0 && x < C;
}

//동서남북상하
int dh[6] = {0,0,0,0,1, -1};
int dy[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
int main() {
	freopen("input.txt", "r", stdin);
	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0) break;
		int h, y, x; int endH, endY, endX;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string temp; cin >> temp;
				board[i].push_back(temp);
				//cout << temp << endl;
				for (int k = 0; k < temp.size(); k++) {
					if (temp[k] == 'S') {
						h = i, y = j, x = k;
					}
					else if (temp[k] == 'E') {
						endH = i, endY = j, endX = k;
					}
				}
			}
			//cout << endl;
		}
		//cout << endl;

		//cost, 점
		priority_queue<pair<int, pair<int, pair<int,int> > > > pq;
		memset(dist, 0x3f3f3f3f, sizeof(dist));

		pq.push(mp(0, mp(h, mp(y, x))));
		dist[h][y][x] = 0;

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int hereH = pq.top().second.first;
			int hereY = pq.top().second.second.first;
			int hereX = pq.top().second.second.second;


			pq.pop();

			if (cost > dist[hereH][hereY][hereX]) continue;

			for (int i = 0; i < 6; i++) {
				int thereH = hereH + dh[i];
				int thereY = hereY + dy[i];
				int thereX = hereX + dx[i];

				int nextDist = cost + 1;

				if (isIn(thereH, thereY, thereX) && dist[thereH][thereY][thereX] > nextDist && board[thereH][thereY][thereX] != '#') {
					pq.push(mp(-nextDist, mp(thereH, mp(thereY, thereX))));
					dist[thereH][thereY][thereX] = nextDist;
				}
			}
		}
		int ret = dist[endH][endY][endX];
		if (ret == 0x3f3f3f3f) {
			cout << "Trapped!" << endl;
		}
		else
			cout << "Escaped in " << ret << " minute(s)." << endl;
	}

	return 0;
}