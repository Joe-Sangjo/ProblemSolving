#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define mp make_pair
vector<string> board;
int N;

//B�� y, x;
vector<pair<int, int> > B;
//E�� y, x;
vector<pair<int, int> > E;
//�߽��� ��ġ
int BCenterY, BCenterX, ECenterY, ECenterX;
//���� 0 : ����  / 1 : ����
int BDir, EDir;

//�� �� �� ��
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


int TurnCheckY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int TurnCheckX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


//������ Ȯ��
bool isIn(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < N;
}

int dist[101][101][2];


int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		board.push_back(temp);
		//cout << board[i] << endl;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'B') {
				B.push_back(mp(i, j));
			}
			else if (board[i][j] == 'E') {
				E.push_back(mp(i, j));
			}
		}
	}

	sort(B.begin(), B.end()); sort(E.begin(), E.end());
	BCenterY = B[1].first; BCenterX = B[1].second; ECenterY = E[1].first; ECenterX = E[1].second;
	//������ ���ΰ� 1, ���ΰ� 0
	BDir = B[0].first != B[1].first;  EDir = E[0].first != E[1].first;
	//cout << BDir << " " << EDir << endl;

	//first.first �� y, first.second �� x, second �� ����
	queue<pair<pair<int, int>, int> > q;
	q.push(mp(mp(BCenterY, BCenterX), BDir));
	
	memset(dist, -1, sizeof(dist));
	dist[BCenterY][BCenterX][BDir] = 0;


	//���� 1, ���� 0
	while (!q.empty()) {

		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		int hereDir = q.front().second;
		
		q.pop();

		if (hereY == ECenterY && hereX == ECenterX && hereDir == EDir)break;
		int hereDist = dist[hereY][hereX][hereDir];


		//�̵�
		//����
		if (hereDir == 0) {
			int leftX = hereX - 1, rightX = hereX + 1;
			int leftY = hereY, rightY = hereY;
			for (int i = 0; i < 4; i++) {
				int leftThereY = leftY + dy[i], leftThereX = leftX + dx[i];
				
				if (!isIn(leftThereY, leftThereX) || board[leftThereY][leftThereX] == '1') {
					continue;
				}

				int thereCenterY = hereY + dy[i], thereCenterX = hereX + dx[i];
				if (!isIn(thereCenterY, thereCenterX) || board[thereCenterY][thereCenterX] == '1') {
					continue;
				}
				int rightThereY = rightY + dy[i], rightThereX = rightX + dx[i];
				if (!isIn(rightThereY, rightThereX) || board[rightThereY][rightThereX] == '1') {
					continue;
				}

				//�̵������ϸ�,,,
				if (dist[thereCenterY][thereCenterX][hereDir] == -1) {
					q.push(mp(mp(thereCenterY, thereCenterX), hereDir));
					dist[thereCenterY][thereCenterX][hereDir] = hereDist + 1;
				}
			}
		}
		//����
		else {
			int upX = hereX, downX = hereX;
			int upY = hereY - 1, downY = hereY + 1;

			for (int i = 0; i < 4; i++) {
				int upThereY = upY + dy[i], upThereX = upX + dx[i];

				if (!isIn(upThereY, upThereX) || board[upThereY][upThereX] == '1') {
					continue;
				}

				int thereCenterY = hereY + dy[i], thereCenterX = hereX + dx[i];
				if (!isIn(thereCenterY, thereCenterX) || board[thereCenterY][thereCenterX] == '1') {
					continue;
				}
				int downThereY = downY + dy[i], downThereX = downX + dx[i];
				if (!isIn(downThereY, downThereX) || board[downThereY][downThereX] == '1') {
					continue;
				}

				//�̵������ϸ�,,,
				if (dist[thereCenterY][thereCenterX][hereDir] == -1) {
					q.push(mp(mp(thereCenterY, thereCenterX), hereDir));
					dist[thereCenterY][thereCenterX][hereDir] = hereDist + 1;
				}
			}


		}


		//ȸ��
		bool turnCheck = true;
		for (int i = 0; i < 8; i++) {
			int aroundY = hereY + TurnCheckY[i];
			int aroundX = hereX + TurnCheckX[i];
			if (!isIn(aroundY, aroundX) || board[aroundY][aroundX] == '1') {
				turnCheck = false;
				break;
			}
		}
		//ȸ�� ������ ��
		int thereDir = !hereDir;
		if (turnCheck && dist[hereY][hereX][thereDir] == -1) {
			q.push(mp(mp(hereY, hereX), thereDir));
			dist[hereY][hereX][thereDir] = hereDist + 1;
		}


		//���� 1, ���� 0
		//for (int dir = 0; dir < 2; dir++) {
		//	if (dir == 0) cout << "����" << endl;
		//	if (dir == 1) cout << "����" << endl;

		//	for (int y = 0; y < N; y++) {
		//		for (int x = 0; x < N; x++) {
		//			printf("%3d", dist[y][x][dir]);
		//		}
		//		cout << endl;
		//	}
		//	cout << endl;
		//}
		//cout << endl << endl;
	}

	if (dist[ECenterY][ECenterX][EDir] == -1) {
		cout << 0 << endl;
	}
	else {
		cout << dist[ECenterY][ECenterX][EDir] << endl;
	}

	//���� 1, ���� 0
	//for (int dir = 0; dir < 2; dir++) {
	//	if (dir == 0) cout << "����" << endl;
	//	if (dir == 1) cout << "����" << endl;

	//	for (int y = 0; y < N; y++) {
	//		for (int x = 0; x < N; x++) {
	//			printf("%3d", dist[y][x][dir]);
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

	return 0;
}