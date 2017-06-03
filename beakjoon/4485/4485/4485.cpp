#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>


using namespace std;



int n;
int board[126][126];
int dist[126][126];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1, -1,0,0 };

inline bool isIn(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n;
}
int main() {
	freopen("input.txt", "r", stdin);
	int prblemNo = 1;
	while (scanf("%d", &n)) {
		if (n == 0) break;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				scanf("%d", &board[y][x]);
				//printf("%d ", board[y][x]);
			}
			//printf("\n");
		}
		memset(dist, 0x3f3f3f3f, sizeof(dist));

		//first는 cost, second.first는 y, second.second는 x
		priority_queue<pair<int, pair<int, int> > > pq;

		dist[0][0] = board[0][0];
		pq.push(make_pair(-board[0][0], make_pair(0,0)));
			

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int hereY = pq.top().second.first;
			int hereX = pq.top().second.second;
			pq.pop();

			if (dist[hereY][hereX] < cost) continue;


			for (int i = 0; i < 4; i++) {

				int thereY = hereY + dy[i];
				int thereX = hereX + dx[i];

				if (!isIn(thereY, thereX)) continue;

				int nextDist = cost + board[thereY][thereX];

				//들어갈만한 가치가 있으면
				if (dist[thereY][thereX] > nextDist) {
					dist[thereY][thereX] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(thereY, thereX)));
				}

			}

		}

		
		printf("Problem %d: %d\n", prblemNo++, dist[n - 1][n - 1]);
	}

	return 0;
}