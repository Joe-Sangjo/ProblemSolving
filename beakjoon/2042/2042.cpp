#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int n, m, k;
long long array[1000001];
long long rangeSum[4000001];

long long init(int left, int right, int node) {
	if (left == right) {
		return rangeSum[node] = array[left];
	}

	int mid = (left + right) / 2;

	return rangeSum[node] = init(left, mid, node * 2)
		+ init(mid + 1, right, node * 2 + 1);
}

long long update(int idx, int newValue, int node,int nodeLeft,int nodeRight) {

	if (idx < nodeLeft || idx > nodeRight) return rangeSum[node];

	if (nodeLeft == nodeRight) {
		return rangeSum[node] = newValue;
	}

	int mid = (nodeLeft + nodeRight) / 2;

	return rangeSum[node] = update(idx, newValue, node * 2 , nodeLeft, mid)
		+ update(idx, newValue, node * 2 + 1, mid + 1, nodeRight);
}

void update(int idx, int newValue) {

	update(idx, newValue, 1, 1, n);
}


long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (right < nodeLeft || left > nodeRight) return 0;

	if (nodeLeft >= left && nodeRight <= right) return rangeSum[node];

	int mid = (nodeLeft + nodeRight) / 2;

	return rangeSum[node] = query(left, right, node * 2 , nodeLeft, mid)
		+ query(left, right, node * 2 + 1, mid + 1, nodeRight);
}


long long query(int left, int right) {
	return query(left, right, 1, 1, n);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &array[i]);
	}
	//첫 노드는 1
	init(1, n , 1);

	for (int i = 0; i < m + k; i++) {
		int a, b; long long c; scanf("%d%d%lld", &a, &b, &c);
		//update
		if (a == 1) {
			update(b, c);
		}
		//query
		else {
			printf("%lld\n", query(b, c));
		}
	}

	return 0;
}