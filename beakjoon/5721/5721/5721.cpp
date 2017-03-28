#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
//최대 행의 개수는 m * n;
int maxIndex = m * n;
//2차원과 1차원을 왔다리 갔다리 잘 하는 것이 핵심

//1차원을 2차원으로.first가 y, second가 x
pair<int, int> convert(int length) {
	int y = length % n == 0 ? length / n : length / n + 1;
	int x = length % n == 0 ? n : length % n;
	return make_pair(y, x);
}

//2차원을 1차원으로.
int convert(int y, int x) {
	return (y - 1) * n + x;
}


//안이면 true           1,1부터 시작이라 . 범위 주의!
bool isIn(int y, int x) {
	return y >= 1 && y <= m && x >= 1 && x <= n;
}


int board[100005];


int dp[100005];
int dy[] = { 0, 0,  2,  2,  2,  2, 2, 2, 2, 2, 3,   3,  3,  3, 3, 3, 3, 3};
int dx[] = { 2, 3, -2, -2, -1, -1, 0, 0, 1, 1, -2, -2, -1, -1, 0, 0, 1, 1};
//index를 선택했을 때, 최대의 사탕개수를 반환한다.
//2차원 1차원 변형 주의! 굳이 사탕을 지울 필요는 없다.
//선택을 할 때 건너서 선택한다.
int solve(int index) {

	//범위를 벗어난 경우
	if (index > m * n) return 0;

	
	int& ret = dp[index];

	if (ret != -1) return ret;

	ret = 0;
		
	int nowY = convert(index).first;
	int nowX = convert(index).second;
	
	//for each (int i in dy)
	//{
	//	int nextY = nowY + dy[i]; int nextX = nowX + dx[i];
	//	if (isIn(nextY, nextX)) {
	//		ret = max(ret, solve(convert(nextY, nextX)));
	//	}
	//}

	//밑밑칸
	for (int i = max(1, nowX - 4); i <= min(nowX + 3,n) ; i++) {
		if(isIn(nowY + 2, i))
			ret = max(ret, solve(convert(nowY + 2, i)));
	}
	//밑밑밑칸
	for (int i = max(1, nowX - 4); i <= min(nowX + 3, n); i++) {
		if (isIn(nowY + 3, i))
			ret = max(ret, solve(convert(nowY + 3, i)));
	}
	//같은 칸
	for (int i = nowX + 2; i <= min(nowX + 3, n); i++) {
		if (isIn(nowY, i))
			ret = max(ret, solve(convert(nowY, i)));
	}
	return ret += board[index];
}


int main() {

	freopen("input.txt", "r", stdin);
	while (1) {
		cin >> m >> n;
		//게임 끝
		if (m == 0 && n == 0) break;

		for (int i = 1; i <= m * n; i++) {
			cin >> board[i];
			//cout << convert(i).first << " " << convert(i).second << "     "<< convert(convert(i).first, convert(i).second)<<endl;
		}
		memset(dp, -1, sizeof(dp));

		int start[4] = { 1, 2, n + 1, n + 2 };

		int ret = 0;
		for (int i = 0; i < 4; i++) {
			if (start[i] <= m * n) {
				ret = max(ret, solve(start[i]));
			}
		}
/*
		for (int i = 1; i <= m * n; i++) {
			ret = max(ret, solve(i));
		}*/
		cout << ret << endl;
	}


	return 0;
}