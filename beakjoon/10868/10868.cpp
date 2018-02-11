#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>


#define MAXN 100001
#define INF 10000000020
using namespace std;
int n, m;

int arr[MAXN], tree[4 * MAXN];

void init(int node, int nodeLeft, int nodeRight) {
	if (nodeLeft == nodeRight) {
		tree[node] = arr[nodeLeft];
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	init(node * 2 + 1, nodeLeft, mid);
	init(node * 2 + 2, mid + 1, nodeRight);
	tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
	if (right < nodeLeft || left > nodeRight) return INF;
	if (left <= nodeLeft && nodeRight <= right) return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;
	int l = query(node * 2 + 1, nodeLeft, mid, left, right);
	int r = query(node * 2 + 2, mid + 1, nodeRight, left, right);
	return min(l, r);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	init(0, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", query(0, 0, n - 1, a - 1, b - 1));
	}




	return 0;
}