#include <iostream>>
#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 1, ����� -1, �ƹ��͵� ������ 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���Ӻ��� (0~ N - 1)
int board[101][101];
// N : ������ ũ��, K ����� ����, L ����� ����
int N, K, L;

//���� �� 0 , ��1, ��2, ��3
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

//////////////////////////�쿡 ���� ���� 
//0�� �Ӹ�, �������� ����
//y�� first, x�� second
deque<pair<int, int> > snake;
//���� ���� ��0 , ��1, ��2, ��3
int nowDir;


//��ĭ�̵� (����� �ȸԴ� ���)
void MoveDontEatApple() {

	//�Ӹ��̵�
	int headY = snake[0].first, headX = snake[0].second;
	headY += dy[nowDir]; headX += dx[nowDir];

	snake.push_front(make_pair(headY, headX));
	//�Ӹ� �ʿ� ���
	board[headY][headX] = 1;

	//���� �ʿ� ����
	int tailY = snake.back().first, tailX = snake.back().second;
	board[tailY][tailX] = 0;

	//���� �̵�
	snake.pop_back();
}
//��ĭ�̵� (����� �Դ� ���)
void MoveEatApple() {

	//�Ӹ��̵�
	int headY = snake[0].first, headX = snake[0].second;
	headY += dy[nowDir]; headX += dx[nowDir];

	snake.push_front(make_pair(headY, headX));
	//�Ӹ� �ʿ� ���
	board[headY][headX] = 1;
}

//������ true, ���̸� false
bool isOut(int y, int x) {
	return y >= N || x >= N || y < 0 || x < 0;
}

//�浹�ϸ� true, �浹���ϸ� false
//�Ӹ��� üũ
bool isBoom() {
	
	int HeadY = snake[0].first, HeadX = snake[0].second;
	for (int i = 1; i < snake.size(); i++) {
		if (HeadY == snake[i].first && HeadX == snake[i].second) {
			return true;
		}
	}
	return false;
}


//���� change
void Rotation(char d) {
	//������ -> ���ڰ� Ŀ����.
	if (d == 'D') {
		nowDir++;
		nowDir %= 4;
	}
	//���� -> ���ڰ� �۾�����.
	else {
		nowDir += 3;
		nowDir %= 4;
	}
}

int changeSeconds[101];
char changeDir[101];


//�׽�Ʈ�� ����Ʈ
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
		//����� �ִ� �ڸ����� -1
		board[inp1 - 1][inp2 - 1] = -1;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> changeSeconds[i] >> changeDir[i];
	}
	


	//���� �浹 �ذ����

	//����Ʈ �̵������� ������
	nowDir = 1;
	//���� �ʱ� ��ġ�� 0,0
	snake.push_front(make_pair(0,0));
	board[0][0] = 1;

	//t�� �ð� , changeIndex �� ������ �ٲ�� index
	int t = 1;
	int changeIndex = 0;
	//while�ѹ��� 1�ʰ� �帥��.
	while (1) {
	//cout << t << endl;
	//	print();
		//////////////////////////�̵��� ���� �ϰ� ���� ������ �ٲ�////////////////////////////////
		int nextY = snake.front().first + dy[nowDir], nextX = snake.front().second + dx[nowDir];
		//������ ���
		if (isOut(nextY, nextX)) {
			cout << t << endl;
			break;
		}

		//�ڽ��� ���� �浹�ϴ� ���
		if (board[nextY][nextX] == 1) {
			cout << t <<endl;
			break;
		}

		//����� �� �Դ� ���
		if (board[nextY][nextX] == 0) {
			MoveDontEatApple();
		}
		////����� �Դ� ���
		else if (board[nextY][nextX] == -1) {
			MoveEatApple();
		}
	

		//������ �ٲٴ� Ÿ�̹�
		if (changeIndex < L) {
			//���� ������ �ٱ;���Ѵٸ�
			if (changeSeconds[changeIndex] == t) {
				Rotation(changeDir[changeIndex]);
				changeIndex++;
			}
		}

		t++;


	}


	return 0;
}