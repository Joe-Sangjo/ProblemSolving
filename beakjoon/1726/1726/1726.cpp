#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>	
#include <cmath>

#define mp make_pair
using namespace std;

int M, N;
vector<vector<int> > board;
//로봇의 위치와 지금 바라보고 있는 방향(동 : 0, 남 : 1, 서 : 2, 북 : 3)
int Ry, Rx, Rd;
//목적지의 위치와 방향(동 : 0, 남 : 1, 서 : 2, 북 : 3)
int Dy, Dx, Dd;


//방향 보정 동 : 0, 남 : 1, 서 : 2, 북 : 3
int DirChange(int d) {
	if (d == 1) return 0;
	if (d == 2) return 2;
	if (d == 3) return 1;
	if (d == 4) return 3;
}


//방향 보정 동 : 0, 남 : 1, 서 : 2, 북 : 3
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0,  -1, 0};

//BFS로 기록을 하는 것.  y, x, d;
int dist[101][101][4];

bool isIn(int y, int x) {
	return y >= 0 && y < M && x >= 0 && x < N;
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> M >> N;

	board = vector<vector<int> >(M);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int temp; cin >> temp;
			board[i].push_back(temp);
			//cout<<board[i][j] << " ";
		}
		//cout << endl;
	}

	cin >> Ry >> Rx >> Rd >> Dy >> Dx >> Dd;
	Ry--; Rx--; Dy--; Dx--;
	memset(dist, -1, sizeof(dist));

	//cout << Ry << " " << Rx << " " << Rd << " " << Dy << " " << Dx << " " << Dd << endl;
	Rd = DirChange(Rd); Dd = DirChange(Dd);
	//F 는 방향, S.F는 y, S.S는 x
	queue<pair<int, pair<int, int> > > q;
	
	q.push(mp(Rd,mp(Ry,Rx)));
	dist[Ry][Rx][Rd] = 0;

	//방향(동 : 0, 남 : 1, 서 : 2, 북 : 3)
	while (!q.empty()) {
		int hereY = q.front().second.first;
		int hereX = q.front().second.second;
		int hereD = q.front().first;

		int hereDist = dist[hereY][hereX][hereD];

		q.pop();

		if (hereY == Dy && hereX == Dx && hereD == Dd) break;

		//이동 위치이동
		for (int i = 1; i <= 3; i++) {
			int thereY = hereY + dy[hereD] * i;
			int thereX = hereX + dx[hereD] * i;
			int thereD = hereD;
			
			if (!isIn(thereY, thereX) || board[thereY][thereX] != 0) {
				break;
			}

			if (dist[thereY][thereX][thereD] == -1 || dist[thereY][thereX][thereD] > hereDist + 1) {
				q.push(mp(thereD, mp(thereY, thereX)));
				dist[thereY][thereX][thereD] = hereDist + 1;
			}
		}



		//방향이동
		int thereD = hereD + 1; thereD %= 4;

		if (dist[hereY][hereX][thereD] == -1) {
			q.push(mp(thereD, mp(hereY, hereX)));
			dist[hereY][hereX][thereD] = hereDist + 1;
		}

		thereD = hereD + 3; thereD %= 4;
		if (dist[hereY][hereX][thereD] == -1) {
			q.push(mp(thereD, mp(hereY, hereX)));
			dist[hereY][hereX][thereD] = hereDist + 1;
		}
	}
	cout << dist[Dy][Dx][Dd] << endl;

	//방향(동 : 0, 남 : 1, 서 : 2, 북 : 3)
	/*for (int dir = 0; dir < 4; dir++) {
		if (dir == 0) cout << "동" << endl;
		if (dir == 1) cout << "남" << endl;
		if (dir == 2) cout << "서" << endl;
		if (dir == 3) cout << "북" << endl;


		for (int y = 0; y < M; y++) {
			for (int x = 0; x < N; x++) {
				cout << dist[y][x][dir] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}*/
	return 0;
}