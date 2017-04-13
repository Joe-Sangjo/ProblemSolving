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

	//동쪽
	void moveEast() {
		int temp = right;
		right = top; top = left; left = bottom; bottom = temp;
	}
	//서쪽
	void moveWest() {
		int temp = left;
		left = top; top = right; right = bottom; bottom = temp;
	}
	//북쪽
	void moveNorth() {
		int temp = up;
		up = top; top = down; down = bottom; bottom = temp;
	}
	//남쪽
	void moveSouth() {
		int temp = down;
		down = top; top = up; up = bottom; bottom = temp;
	}
	//동 : 1 // 서 : 2 // 북 : 3 // 남 : 4
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
		//동 : 1 // 서 : 2 // 북 : 3 // 남 : 4
		
		//안이 아닐 경우 넘어 간다.
		if (!isIn(hereY + dy[order], hereX + dx[order])) {
			continue;
		}

		hereY += dy[order]; hereX += dx[order];
		dice.move(order);
		//칸이 0 -> 주사위 바닥면이 칸에 복사
		if(map[hereY][hereX] == 0){
			map[hereY][hereX] = dice.bottom;
		}
		//칸이 0이 아님 -> 칸이 주사위 바닥면으로 복사, 칸이 0이 됨.
		else {
			dice.bottom = map[hereY][hereX];
			map[hereY][hereX] = 0;
		}
		cout << dice.top << endl;
	}


	return 0;
}