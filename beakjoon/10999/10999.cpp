#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

typedef long long ll;

using namespace std;
#define MAX 3000000
void swap(int &a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int n, m, k;
ll tree[3000001];
ll lazy[3000001];

void Propagate(int node, int nodeLeft, int nodeRight) {
	if (lazy[node] == 0) return;

	if (nodeLeft != nodeRight) {
		//nodeLeft�� nodeRight�� �ٸ��ٴ� ���� �׻� �����ڽ��� �ִٴ� ��!
		lazy[node * 2] += lazy[node];
		if (node * 2 + 1 < MAX) lazy[node * 2 + 1] += lazy[node];
	}

	tree[node] += (nodeRight - nodeLeft + 1) * lazy[node];
	lazy[node] = 0;
}
ll update_new(int node, int nodeLeft, int nodeRight, int idx, int value) {
	Propagate(node, nodeLeft, nodeRight);
	//2. �־��� ������ node�� ǥ���ϴ� ������ �ٱ������� Ȯ���Ѵ�.
	if (idx < nodeLeft || idx > nodeRight) return tree[node];

	//1. �־��� ������ node�� ǥ���ϴ� ������ �������� Ȯ���Ѵ�.
	if (nodeLeft == nodeRight) {
		return tree[node] = value;
	}

	//3. ȣ���Ѵ�.
	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = update_new(node * 2, nodeLeft, mid, idx, value)
		+ update_new(node * 2 + 1, mid + 1, nodeRight, idx, value);
}

ll update_add(int node, int nodeLeft, int nodeRight, int idx, int value) {
	if (nodeLeft == nodeRight) {
		return tree[node] += value;
	}

	if (idx < nodeLeft || idx > nodeRight) {
		return 0;
	}

	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = update_add(node * 2, nodeLeft, mid, idx, value)
		+ update_add(node * 2 + 1, mid + 1, nodeRight,idx ,value);
}

ll update_add_range(int node, int nodeLeft, int nodeRight, int left, int right, int value) {
	Propagate(node, nodeLeft, nodeRight);
	//1. �־��� ������ node�� ǥ���ϴ� ������ �����ϴ� ���
	if (left <= nodeLeft && nodeRight <= right) {
		lazy[node] += value;
		Propagate(node, nodeLeft, nodeRight);
		return tree[node];
	}

	//2. ���� ���� ���
	if (left > nodeRight || right < nodeLeft) {
		return tree[node];
	}

	int mid = (nodeLeft + nodeRight) / 2;

	return tree[node] = update_add_range(node * 2, nodeLeft, mid, left, right, value)
		+ update_add_range(node * 2 + 1, mid + 1, nodeRight, left, right, value);
}

ll query(int node, int nodeLeft, int nodeRight, int left, int right) {
	Propagate(node, nodeLeft, nodeRight);
	//1. �־��� ������ node�� ǥ���ϴ� ������ �����ϴ� ���
	if (left <= nodeLeft && nodeRight <= right) {
		return tree[node];
	}
	//2. �־��� ������ node�� ǥ���ϴ� ������ ���� ���
	if (nodeRight < left || nodeLeft > right) return 0;

	//3. �б�
	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = query(node * 2, nodeLeft, mid, left, right)
		+ query(node * 2 + 1, mid + 1, nodeRight, left, right);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	int a, b, c,d;
	for (int i = 1; i <= n; i++) {
		int in;
		cin >> in;
		update_new(1, 1, n, i, in);
	}
	
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			if (b > c) swap(b, c);
			update_add_range(1, 1, n, b, c, d);
		}
		else if (a == 2) {
			if (b > c) swap(b, c);
			cout << query(1, 1, n, b, c)<<endl;
		}
	}

	return 0;
}