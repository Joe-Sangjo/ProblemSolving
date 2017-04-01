#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
int w, h;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int dist[1001][1001];
int fireDist[1001][1001];

//탈출 -> true면 게임끝!
bool isOut(int y, int x) {
	return x >= w || x < 0 || y >= h || y < 0;
}

void printBoard(vector<string>& board) {
	for (int i = 0; i < board.size(); i++) {
		cout << board[i] << endl;
	}
	cout << endl;
}
void printFire() {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			printf("%4d", fireDist[y][x]);
		}
		cout << endl;
	}
	cout << endl;
}
void printDist() {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			printf("%4d", dist[y][x]);
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	while (TC--) {
		
			vector<string> board;
			//cout << TC << endl;
			cin >> w >> h;
			//불의 위치를 담는 queue
			queue<pair<int, int> > fire;
			//나의 위치를 담는다.
			int myY, myX;

			memset(fireDist, -1, sizeof(fireDist));
			for (int i = 0; i < h; i++) {
				string temp;
				cin >> temp;

				board.push_back(temp);
				for (int j = 0; j < temp.size(); j++) {
					if (board[i][j] == '*') {
						fire.push(make_pair(i, j));
						fireDist[i][j] = 0;
					}
					else if (board[i][j] == '@') {
						myY = i; myX = j;
					}
				}
			}


				memset(dist, -1, sizeof(dist));

				dist[myY][myX] = 0;
				queue<pair<int, int> > q;
				q.push(make_pair(myY, myX));
				bool ret = false;
				int maxDIst = 0;
				while (!q.empty()) {

					int nowY = q.front().first;
					int nowX = q.front().second;

					q.pop();

					int hereDist = dist[nowY][nowX];

					//불을 번져준다.
					while (!fire.empty()) {
						int fireHereY = fire.front().first;
						int fireHereX = fire.front().second;

						int fireHereDist = fireDist[fireHereY][fireHereX];
						//멈추는 조건 넣어야함.
						if (fireHereDist > hereDist) break;
						board[fireHereY][fireHereX] = '*';
						fire.pop();
						for (int i = 0; i < 4; i++) {
							int fireThereY = fireHereY + dy[i];
							int fireThereX = fireHereX + dx[i];

							if (!isOut(fireThereY, fireThereX) && fireDist[fireThereY][fireThereX] == -1 && board[fireThereY][fireThereX] != '#') {
								fireDist[fireThereY][fireThereX] = fireHereDist + 1;
								fire.push(make_pair(fireThereY, fireThereX));
							}
						}
					}


					//다음으로 이동
					for (int i = 0; i < 4; i++) {
						int nextY = nowY + dy[i], nextX = nowX + dx[i];
						if (isOut(nextY, nextX)) {
							ret = true;
							maxDIst = hereDist + 1;
							break;
						}

						if (board[nextY][nextX] != '#' && fireDist[nextY][nextX] == -1 && dist[nextY][nextX] == -1) {
							q.push(make_pair(nextY, nextX));
							dist[nextY][nextX] = hereDist + 1;
						}
					}
					
					if (ret) break;
				}

				if (!ret)
					cout << "IMPOSSIBLE" << endl;
				else
					cout << maxDIst << endl;
	}



	return 0;
}