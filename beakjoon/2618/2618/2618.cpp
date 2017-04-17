#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#define mp make_pair
using namespace std;
int N, W;
pair<int, int> incident[1001];
pair<int, int> path[1001][1001];

int dp[1001][1001];
int move(int from, int to) {
	return abs(incident[from].first - incident[to].first) + abs(incident[from].second - incident[to].second);
}
int solve(int a, int b) {
	
	int& ret = dp[a][b];

	if (ret != -1) return ret;

	if (a == W || b == W) return ret = 0;

	int next = max(a, b) + 1;

	//1번 경찰차가 이동
	int cost1;
	if (a == 0) {
		cost1 = incident[next].first - 1 + incident[next].second - 1;
	}
	else {
		cost1 = move(a, next);
	}
	int ret1 = solve(next, b) + cost1;
	//2번 경찰차가 이동
	int cost2;
	if (b == 0) {
		cost2 = 2 * N - incident[next].first - incident[next].second;
	}
	else {
		cost2 = move(b, next);
	}
	int ret2 = solve(a, next) + cost2;

	ret = min(ret1, ret2);

	if (ret1 < ret2) {
		path[a][b] = mp(next, b);
	}
	else {
		path[a][b] = mp(a, next);
	}

	return ret;

}
void reconstruct(int a, int b) {
	if (a == W || b == W) return;


	//2가 이동
	if (path[a][b].first < path[a][b].second) {
		cout << 2 << endl;
		reconstruct(a, path[a][b].second);
	}
	else {
		cout << 1 << endl;
		reconstruct(path[a][b].first, b);
	}


}
int main() {
	freopen("input.txt", "r", stdin);
	memset(dp,-1, sizeof(dp));
	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		int a, b; cin >> a >> b;
		incident[i] = mp(a, b);
	}
	



	int ret = solve(0, 0);
	cout << ret << endl;
	/*for (int i = 0; i <= W; i++) {
		for (int j = 0; j <= W; j++) {
			cout << path[i][j].first << " " << path[i][j].second << "    ";
		}
		cout << endl;
	}*/
	reconstruct(0, 0);
	return 0;
}