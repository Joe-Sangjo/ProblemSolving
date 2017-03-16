#include <iostream>>
#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 뱀은 1, 사과는 -1, 아무것도 없으면 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//게임보드 (0~ N - 1)
int board[101][101];
// N : 보드판 크기, K 사과의 개수, L 명령의 개수
int N, K, L;

//방향 북 0 , 동1, 남2, 서3
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

//////////////////////////뱀에 대한 정보 
//0은 머리, 마지막은 꼬리
//y가 first, x는 second
deque<pair<int, int> > snake;
//지금 방향 북0 , 동1, 남2, 서3
int nowDir;


//한칸이동 (사과를 안먹는 경우)
void MoveDontEatApple() {

	//머리이동
	int headY = snake[0].first, headX = snake[0].second;
	headY += dy[nowDir]; headX += dx[nowDir];

	snake.push_front(make_pair(headY, headX));
	//머리 맵에 기록
	board[headY][headX] = 1;

	//꼬리 맵에 지움
	int tailY = snake.back().first, tailX = snake.back().second;
	board[tailY][tailX] = 0;

	//꼬리 이동
	snake.pop_back();
}
//한칸이동 (사과를 먹는 경우)
void MoveEatApple() {

	//머리이동
	int headY = snake[0].first, headX = snake[0].second;
	headY += dy[nowDir]; headX += dx[nowDir];

	snake.push_front(make_pair(headY, headX));
	//머리 맵에 기록
	board[headY][headX] = 1;
}

//나가면 true, 안이면 false
bool isOut(int y, int x) {
	return y >= N || x >= N || y < 0 || x < 0;
}

//충돌하면 true, 충돌안하면 false
//머리만 체크
bool isBoom() {
	
	int HeadY = snake[0].first, HeadX = snake[0].second;
	for (int i = 1; i < snake.size(); i++) {
		if (HeadY == snake[i].first && HeadX == snake[i].second) {
			return true;
		}
	}
	return false;
}


//방향 change
void Rotation(char d) {
	//오른쪽 -> 숫자가 커진다.
	if (d == 'D') {
		nowDir++;
		nowDir %= 4;
	}
	//왼쪽 -> 숫자가 작아진다.
	else {
		nowDir += 3;
		nowDir %= 4;
	}
}

int changeSeconds[101];
char changeDir[101];


//테스트용 프린트
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main() {

	freopen("input.txt", "r", stdin);
	memset(board, 0, sizeof(board));
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int inp1, inp2;
		cin >> inp1 >> inp2;
		//사과가 있는 자리에는 -1
		board[inp1 - 1][inp2 - 1] = -1;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> changeSeconds[i] >> changeDir[i];
	}
	


	//아직 충돌 해결안함

	//디폴트 이동방향은 오른쪽
	nowDir = 1;
	//뱀의 초기 위치는 0,0
	snake.push_front(make_pair(0,0));
	board[0][0] = 1;

	//t는 시간 , changeIndex 는 방향이 바뀌는 index
	int t = 1;
	int changeIndex = 0;
	//while한번은 1초가 흐른것.
	while (1) {
	//cout << t << endl;
	//	print();
		//////////////////////////이동을 먼저 하고 나서 방향을 바꿈////////////////////////////////
		int nextY = snake.front().first + dy[nowDir], nextX = snake.front().second + dx[nowDir];
		//나가는 경우
		if (isOut(nextY, nextX)) {
			cout << t << endl;
			break;
		}

		//자신의 몸과 충돌하는 경우
		if (board[nextY][nextX] == 1) {
			cout << t <<endl;
			break;
		}

		//사과를 안 먹는 경우
		if (board[nextY][nextX] == 0) {
			MoveDontEatApple();
		}
		////사과를 먹는 경우
		else if (board[nextY][nextX] == -1) {
			MoveEatApple();
		}
	

		//방향을 바꾸는 타이밍
		if (changeIndex < L) {
			//만약 방향이 바귀어야한다면
			if (changeSeconds[changeIndex] == t) {
				Rotation(changeDir[changeIndex]);
				changeIndex++;
			}
		}

		t++;


	}


	return 0;
}