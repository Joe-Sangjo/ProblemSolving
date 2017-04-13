#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char board[101][101];
int n;

vector<int> start;//������ġ
vector<int> finish;//����ġ
int visited[10001][10001];

int main() {

	memset(visited, -1, sizeof(visited));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'B')
				start.push_back(i*n + j);
			else if (board[i][j] == 'E')
				finish.push_back(i*n + j);
		}
	}

	queue<pair<int, int> > q;//�볪�� �� ���� �������
	q.push(make_pair(start[0], start[2]));
	visited[start[0]][start[2]] = 0;

	bool ret = false;
	while (!q.empty()) {

		vector<pair<int, int> > now(3);//���� �볪���� ��ǥ�� ����
		int depth = visited[q.front().first][q.front().second];
		now[0] = make_pair(q.front().first / n, q.front().first % n);//���� y, x��ǥ
		now[2] = make_pair(q.front().second / n, q.front().second % n);
		int temp = (q.front().first + q.front().second) / 2;
		now[1] = make_pair(temp / n, temp % n);

		//cout << "hi" << " " << q.front().first << " " << temp << " " << q.front().second << " " << depth << "\n";
		q.pop();

		if (now[0].first * n + now[0].second == finish[0] && now[2].first * n + now[2].second == finish[2]) {
			//���� ���������� ���̸� ����Ѵ�
			cout << depth;
			ret = true;
			break;
		}

		//�� �� �ִ� �͵��� �־���
		for (int i = 0; i < 4; i++) {
			//��ĭ�� �ű� �� �ִ� �� Ȯ��
			//1. �Ѿ�� �ʴ� ��
			//2. �ٸ� ������ ���� ��(��� �糡�� Ȯ���ϸ� �ȵ�. ���� ����غ��� �˾���)
			//3. �̹� �湮�� ���� �ƴ� ��
			//�� �� �볪���� Ȯ���ϸ� ��
			//�ƴϴ� �糡�� Ȯ�����ָ� �ȵ�!
			int a = now[0].first + dy[i];
			int b = now[0].second + dx[i];
			int c = now[2].first + dy[i];
			int d = now[2].second + dx[i];
			if (a >= 0 && b >= 0 && c < n && d < n)
				if (board[a][b] != '1' && board[c][d] != '1' && board[now[1].first + dy[i]][now[1].second + dx[i]] != '1')
					if (visited[n*a + b][n*c + d] == -1) {
						//cout << "a ";
						q.push(make_pair(n*a + b, n*c + d));
						visited[n*a + b][n*c + d] = depth + 1;
						//cout << n*a + b << " " << n*c + d << "\n";
					}
		}

		//ȸ��
		if (now[0].first == now[2].first) {
			//y��ǥ�� ���� ���
			if (now[0].first - 1 >= 0 && now[0].first + 1 < n)
				if (board[now[0].first - 1][now[0].second] != '1' && board[now[1].first - 1][now[1].second] != '1' && board[now[2].first - 1][now[2].second] != '1')
					if (board[now[0].first + 1][now[0].second] != '1' && board[now[1].first + 1][now[1].second] != '1' && board[now[2].first + 1][now[2].second] != '1')
						if (visited[(now[1].first - 1)*n + now[1].second][(now[1].first + 1)*n + now[1].second] == -1) {
							//cout << "b ";
							q.push(make_pair((now[1].first - 1)*n + now[1].second, (now[1].first + 1)*n + now[1].second));
							visited[(now[1].first - 1)*n + now[1].second][(now[1].first + 1)*n + now[1].second] = depth + 1;
							//cout << (now[1].first - 1)*n + now[1].second << " " << (now[1].first + 1)*n + now[1].second << "\n";
						}
		}
		else if (now[0].second == now[2].second) {
			//x��ǥ�� ���� ���
			if (now[0].second - 1 >= 0 && now[0].second + 1 < n)
				if (board[now[0].first][now[0].second - 1] != '1' && board[now[1].first][now[1].second - 1] != '1' && board[now[2].first][now[2].second - 1] != '1')
					if (board[now[0].first][now[0].second + 1] != '1' && board[now[1].first][now[1].second + 1] != '1' && board[now[2].first][now[2].second + 1] != '1')
						if (visited[now[1].first*n + now[1].second - 1][now[1].first*n + now[1].second + 1] == -1) {
							//cout << "c ";
							q.push(make_pair(now[1].first*n + now[1].second - 1, now[1].first*n + now[1].second + 1));
							visited[now[1].first*n + now[1].second - 1][now[1].first*n + now[1].second + 1] = depth + 1;
							//cout << now[1].first*n + now[1].second - 1 << " " << now[1].first*n + now[1].second + 1 << "\n";
						}
		}
	}

	if (!ret)
		cout << "0";
	return 0;

}