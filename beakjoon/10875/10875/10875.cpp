#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define mp make_pair
#define INF 200000000000
struct DATA {
	int nowx;
	int nowy;
	int nextx;
	int nexty;
};
vector <DATA> row;
vector <DATA> col;
int x = 0, y = 0;         //현재 좌표를 나타냄. 
long long ret = 0;
int dir = 1;
int L, N;
int check(long long a) {
	long long tmp = INF;
	//현재 방향이 1, 3이라면 수직선이랑 체크. 
	if (dir == 1) {
		for (auto i = 0; i<col.size(); i++) {
			if (x == col[i].nextx && y == col[i].nexty) continue;
			if (x == col[i].nowx && y == col[i].nowy) continue;
			if (x <= col[i].nowx && x + a >= col[i].nowx && y >= col[i].nowy && y <= col[i].nexty) {
				int k = col[i].nowx - x;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
		for (auto i = 0; i<row.size(); i++) {
			if (x <= row[i].nowx && y == row[i].nowy && x + a >= row[i].nowx) {
				int k = row[i].nowx - x;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
	}
	else if (dir == 3) {
		for (auto i = 0; i<col.size(); i++) {
			if (x == col[i].nextx && y == col[i].nexty) continue;
			if (x == col[i].nowx && y == col[i].nowy) continue;
			if (x >= col[i].nowx && x - a <= col[i].nowx && y >= col[i].nowy && y <= col[i].nexty) {
				int k = col[i].nowx - x;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
		for (auto i = 0; i<row.size(); i++) {
			if (x >= row[i].nextx && y == row[i].nowy && x - a <= row[i].nextx) {
				int k = row[i].nextx - x;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
	}
	else if (dir == 2) {
		for (auto i = 0; i<row.size(); i++) {
			if (x == row[i].nextx && y == row[i].nexty) continue;
			if (x == row[i].nowx && y == row[i].nowy) continue;
			if (y <= row[i].nowy && y + a >= row[i].nowy && x >= row[i].nowx && x <= row[i].nextx) {
				int k = row[i].nowy - y;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
		for (auto i = 0; i<col.size(); i++) {
			if (x == col[i].nowx && y <= col[i].nowy && y + a >= col[i].nowy) {
				int k = col[i].nowy - y;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
	}
	else if (dir == 0) {
		for (auto i = 0; i<row.size(); i++) {
			if (x == row[i].nextx && y == row[i].nexty) continue;
			if (x == row[i].nowx && y == row[i].nowy) continue;
			if (y >= row[i].nowy && y - a <= row[i].nowy && x >= row[i].nowx && x <= row[i].nextx) {
				int k = row[i].nowy - y;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
		for (auto i = 0; i<col.size(); i++) {
			if (x == col[i].nowx && y >= col[i].nexty && y - a <= col[i].nexty) {
				int k = col[i].nexty - y;
				if (tmp >abs(k)) tmp = abs(k);
			}
		}
	}
	if (tmp != INF) {
		ret += tmp;
		return 0;
	}
	else return 1;
}
int func(int a, char d) {
	if (check(a) == 0) return 0;
	if (dir == 1) {
		row.push_back({ x,y,x + a,y });
		x += a;
	}
	else if (dir == 2) {
		col.push_back({ x,y,x,y + a });
		y += a;
	}
	else if (dir == 3) {
		row.push_back({ x - a,y,x,y });
		x -= a;
	}
	else if (dir == 0) {
		col.push_back({ x,y - a,x ,y });
		y -= a;
	}
	if (d == 'L') {
		dir = (dir + 1) % 4;
	}
	else if (d == 'R') {
		dir = (dir + 3) % 4;
	}
	//시간 증가. 
	ret += a;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	bool flag = 0;
	cin >> L;
	cin >> N;
	row.push_back({ -L - 1,-L - 1,L + 1,-L - 1 });
	row.push_back({ -L - 1,L + 1,L + 1,L + 1 });
	col.push_back({ -L - 1,-L - 1,-L - 1,L + 1 });
	col.push_back({ L + 1,-L - 1,L + 1,L + 1 });
	int cost;
	char direction;
	for (int i = 0; i<N; i++) {
		cin >> cost >> direction;
		if (flag == 1) continue;
		if (func(cost, direction) == 0) flag = 1;
	}
	if (flag == 0) check(300000000);
	cout << ret;
}