#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1000000001

typedef long long ll;
using namespace std;
int n, m;
vector<int> tree;
bool decision(int h) {

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		int diff = tree[i] - h;
		sum += diff > 0 ? diff : 0;
	}
	return sum >= m;
}
int optimal() {
	int lo = 0; int hi = MAX;

	int mid;

	for (int i = 0; i < 100; i++) {
		mid = (hi + lo) / 2;
		if (decision(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return mid;
}

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d %d", &n, &m);
	//printf("%d %d", n, m);
	for (int i = 0; i < n; i++) {
		int inp; scanf("%d", &inp);
		tree.push_back(inp);
		//printf("%d\n", tree[i]);
	}
	printf("%d", optimal());
	return 0;
}