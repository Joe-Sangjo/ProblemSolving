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

vector<int> start;//시작위치
vector<int> finish;//끝위치
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

	queue<pair<int, int> > q;//통나무 양 끝이 들어있음
	q.push(make_pair(start[0], start[2]));
	visited[start[0]][start[2]] = 0;

	bool ret = false;
	while (!q.empty()) {

		vector<pair<int, int> > now(3);//현재 통나무의 좌표를 저장
		int depth = visited[q.front().first][q.front().second];
		now[0] = make_pair(q.front().first / n, q.front().first % n);//각각 y, x좌표
		now[2] = make_pair(q.front().second / n, q.front().second % n);
		int temp = (q.front().first + q.front().second) / 2;
		now[1] = make_pair(temp / n, temp % n);

		//cout << "hi" << " " << q.front().first << " " << temp << " " << q.front().second << " " << depth << "\n";
		q.pop();

		if (now[0].first * n + now[0].second == finish[0] && now[2].first * n + now[2].second == finish[2]) {
			//끝에 도달했으면 깊이를 출력한다
			cout << depth;
			ret = true;
			break;
		}

		//갈 수 있는 것들을 넣어줌
		for (int i = 0; i < 4; i++) {
			//한칸씩 옮길 수 있는 지 확인
			//1. 넘어가지 않는 지
			//2. 다른 나무는 없는 지(얘는 양끝만 확인하면 안됨. 직접 출력해보고 알았음)
			//3. 이미 방문한 것은 아닌 지
			//양 끝 통나무만 확인하면 됨
			//아니다 양끝만 확인해주면 안됨!
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

		//회전
		if (now[0].first == now[2].first) {
			//y좌표가 같은 경우
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
			//x좌표가 같은 경우
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