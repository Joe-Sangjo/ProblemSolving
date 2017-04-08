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
//�κ��� ��ġ�� ���� �ٶ󺸰� �ִ� ����(�� : 0, �� : 1, �� : 2, �� : 3)
int Ry, Rx, Rd;
//�������� ��ġ�� ����(�� : 0, �� : 1, �� : 2, �� : 3)
int Dy, Dx, Dd;


//���� ���� �� : 0, �� : 1, �� : 2, �� : 3
int DirChange(int d) {
	if (d == 1) return 0;
	if (d == 2) return 2;
	if (d == 3) return 1;
	if (d == 4) return 3;
}


//���� ���� �� : 0, �� : 1, �� : 2, �� : 3
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0,  -1, 0};

//BFS�� ����� �ϴ� ��.  y, x, d;
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
	//F �� ����, S.F�� y, S.S�� x
	queue<pair<int, pair<int, int> > > q;
	
	q.push(mp(Rd,mp(Ry,Rx)));
	dist[Ry][Rx][Rd] = 0;

	//����(�� : 0, �� : 1, �� : 2, �� : 3)
	while (!q.empty()) {
		int hereY = q.front().second.first;
		int hereX = q.front().second.second;
		int hereD = q.front().first;

		int hereDist = dist[hereY][hereX][hereD];

		q.pop();

		if (hereY == Dy && hereX == Dx && hereD == Dd) break;

		//�̵� ��ġ�̵�
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



		//�����̵�
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

	//����(�� : 0, �� : 1, �� : 2, �� : 3)
	/*for (int dir = 0; dir < 4; dir++) {
		if (dir == 0) cout << "��" << endl;
		if (dir == 1) cout << "��" << endl;
		if (dir == 2) cout << "��" << endl;
		if (dir == 3) cout << "��" << endl;


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