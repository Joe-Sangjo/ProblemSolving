#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	
	vector<pair<int, int> > list;
	
	vector<pair<int, int> > list2;

	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x,&y);
		list.push_back(make_pair(x, y));

		list2.push_back(make_pair(y, x));
	}

	sort(list.begin(), list.end());

	sort(list2.begin(), list2.end());

	int ret = 0x3f3f3f3f;
	for (int i = 0; i < n - 1; i++) {
		int diff1 = (list[i].first - list[i + 1].first) * (list[i].first - list[i + 1].first);
		int diff2 = (list[i].second - list[i + 1].second) * (list[i].second - list[i + 1].second);
		int diff3 = (list2[i].first - list2[i + 1].first) * (list2[i].first - list2[i + 1].first);
		int diff4 = (list2[i].second - list2[i + 1].second) * (list2[i].second - list2[i + 1].second);

		ret = min(ret, diff1 + diff2);
		ret = min(ret, diff3 + diff4);
	}

	cout << ret << endl;

	return 0;
}