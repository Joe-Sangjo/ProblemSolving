#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M, X, Y, K;
int map[21][21];
class Dice{
public :
	int top, right, left, up, down, bottom;
	Dice() {
		top = right = left = up = down = bottom = 0;
	}

	//����
	void moveEast() {
		int temp = right;
		right = top; top = left; left = bottom; bottom = temp;
	}
	//����
	void moveWest() {
		int temp = left;
		left = top; top = right; right = bottom; bottom = temp;
	}
	//����
	void moveNorth() {
		int temp = up;
		up = top; top = down; down = bottom; bottom = temp;
	}
	//����
	void moveSouth() {
		int temp = down;
		down = top; top = up; up = bottom; bottom = temp;
	}
	//�� : 1 // �� : 2 // �� : 3 // �� : 4
	void move(int dir) {
		switch (dir)
		{
			case 1:
				moveEast();
				break;
			case 2:
				moveWest();
				break;
			case 3:
				moveNorth();
				break;
			case 4:
				moveSouth();
				break;
		}
	}
};

bool isIn(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> N >> M >> Y >> X >> K;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	int hereY = Y, hereX = X;
	int dy[5] = {0,0,0,-1,1};
	int dx[5] = {0,1,-1,0,0};
	Dice dice;
	for (int i = 0; i < K; i++) {
		int order; cin >> order;
		//�� : 1 // �� : 2 // �� : 3 // �� : 4
		
		//���� �ƴ� ��� �Ѿ� ����.
		if (!isIn(hereY + dy[order], hereX + dx[order])) {
			continue;
		}

		hereY += dy[order]; hereX += dx[order];
		dice.move(order);
		//ĭ�� 0 -> �ֻ��� �ٴڸ��� ĭ�� ����
		if(map[hereY][hereX] == 0){
			map[hereY][hereX] = dice.bottom;
		}
		//ĭ�� 0�� �ƴ� -> ĭ�� �ֻ��� �ٴڸ����� ����, ĭ�� 0�� ��.
		else {
			dice.bottom = map[hereY][hereX];
			map[hereY][hereX] = 0;
		}
		cout << dice.top << endl;
	}


	return 0;
}