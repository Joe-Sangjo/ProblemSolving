#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
typedef long long ll;

using namespace std;
int n, m;

vector<ll> maxTree;
vector<ll> minTree;
vector<ll> arr;

void init(int node, int nodeLeft, int nodeRight) {

	if (nodeLeft == nodeRight) {
		maxTree[node] = arr[nodeLeft];
		minTree[node] = arr[nodeLeft];
		return;
	}
	
	int mid = (nodeLeft + nodeRight) >> 1;

	init(node * 2 + 1, nodeLeft, mid); init(node * 2 + 2, mid + 1, nodeRight);

	maxTree[node] = max(maxTree[node * 2 + 1], maxTree[node * 2 + 2]);
	minTree[node] = min(minTree[node * 2 + 1], minTree[node * 2 + 2]);
}

ll maxQuery(int node, int nodeLeft, int nodeRight, int left, int right) {
	if (left > nodeRight || right < nodeLeft)
		return 0;

	if (left <= nodeLeft && nodeRight <= right)
		return maxTree[node];

	int mid = (nodeLeft + nodeRight) >> 1;
	
	ll l = maxQuery(node * 2 + 1, nodeLeft, mid, left, right);
	ll r = maxQuery(node * 2 + 2, mid + 1, nodeRight, left, right);
	return max(l, r);
}

ll minQuery(int node, int nodeLeft, int nodeRight, int left, int right) {

	if (left > nodeRight || right < nodeLeft)
		return 1111111111;

	if (left <= nodeLeft && nodeRight <= right)
		return minTree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	ll l = minQuery(node * 2 + 1, nodeLeft, mid, left, right);
	ll r = minQuery(node * 2 + 2, mid + 1, nodeRight, left, right);
	
	return min(l, r);
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;

	maxTree = vector<ll>(4 * n);
	minTree = vector<ll>(4 * n);
	arr = vector<ll>(n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	init(0, 0, n - 1);

	for (int i = 0; i < m; i++) {

		int a, b; scanf("%d%d", &a, &b);
		a--, b--;
		printf("%lld %lld\n", minQuery(0, 0, n - 1, a, b), maxQuery(0, 0, n - 1, a, b));
	}

	return 0;
}