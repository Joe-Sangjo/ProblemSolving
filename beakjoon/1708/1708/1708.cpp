#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

//first == x, second == y
vector<pair<int, int> > point;


//����AB�� ���� AC�� ����. ���� ���̸� C�� AB�� ���ʿ� �ִٴ� ��!!
int cross(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first -  a.first);
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	point = vector<pair<int, int> >(n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &point[i].first, &point[i].second);
		//printf("%d %d\n", point[i].first, point[i].second);
	}

	sort(point.begin(), point.end());

	for (int i = 0; i < n - 2; i++) {

		
	}

	return 0;
}