#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
//�ִ� ���� ������ m * n;
int maxIndex = m * n;
//2������ 1������ �Դٸ� ���ٸ� �� �ϴ� ���� �ٽ�

//1������ 2��������.first�� y, second�� x
pair<int, int> convert(int length) {
	int y = length % n == 0 ? length / n : length / n + 1;
	int x = length % n == 0 ? n : length % n;
	return make_pair(y, x);
}

//2������ 1��������.
int convert(int y, int x) {
	return (y - 1) * n + x;
}


//���̸� true           1,1���� �����̶� . ���� ����!
bool isIn(int y, int x) {
	return y >= 1 && y <= m && x >= 1 && x <= n;
}


int board[100005];


int dp[100005];
int dy[] = { 0, 0,  2,  2,  2,  2, 2, 2, 2, 2, 3,   3,  3,  3, 3, 3, 3, 3};
int dx[] = { 2, 3, -2, -2, -1, -1, 0, 0, 1, 1, -2, -2, -1, -1, 0, 0, 1, 1};
//index�� �������� ��, �ִ��� ���������� ��ȯ�Ѵ�.
//2���� 1���� ���� ����! ���� ������ ���� �ʿ�� ����.
//������ �� �� �ǳʼ� �����Ѵ�.
int solve(int index) {

	//������ ��� ���
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

	//�ع�ĭ
	for (int i = max(1, nowX - 4); i <= min(nowX + 3,n) ; i++) {
		if(isIn(nowY + 2, i))
			ret = max(ret, solve(convert(nowY + 2, i)));
	}
	//�عع�ĭ
	for (int i = max(1, nowX - 4); i <= min(nowX + 3, n); i++) {
		if (isIn(nowY + 3, i))
			ret = max(ret, solve(convert(nowY + 3, i)));
	}
	//���� ĭ
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
		//���� ��
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