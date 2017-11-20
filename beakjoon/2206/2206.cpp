#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef struct point {
	int y, x, z;
	point() {}; point(int y_, int x_, int z_) :y(y_), x(x_), z(z_) {}
	void operator = (point a) {
		this->x = a.x;
		this->y = a.y;
		this->z = a.z;
	}
}p;

int n, m;
bool isIn(int y, int x) {
	return y < n && x < m && y >= 0 && x >= 0;
}

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

string map[1001];
int dist[1001][1001][2];
int main() {
	freopen("input.txt", "r", stdin);
	//scanf("%d %d", &n, &m);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		// cout<<map[i]<<'\n';
	}
	memset(dist, INF, sizeof(dist));
	p start(0, 0, 0);
	queue<p> q;

	dist[0][0][0] = 1;
	//dist[0][0][1] = 1;
	q.push(start);
	while (!q.empty()) {
		p here = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = here.x + dx[i];
			int ny = here.y + dy[i];
			if (isIn(ny, nx)) {
				if (map[ny][nx] == '0') {
					if (dist[ny][nx][here.z] > dist[here.y][here.x][here.z] + 1) {
						dist[ny][nx][here.z] = dist[here.y][here.x][here.z] + 1;
						p next(ny, nx, here.z);
						q.push(next);
					}
				}
				else {
					if (here.z == 1)	continue;
					if (dist[ny][nx][1] > dist[here.y][here.x][here.z] + 1) {
						dist[ny][nx][1] = dist[here.y][here.x][here.z] + 1;
						p next(ny, nx, 1);
						q.push(next);
					}
				}
			}
		}
	}

	int ret = min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	if (ret == INF) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", ret);
	}


	return 0;
}