#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

//index번째 아이로 올 동안 candy개 가져갔을 경우
int solve(int index, int candy) {
	//cout << index << " " << candy << endl;
	int ret = 0;
	if (index == 0) {
		for (int nowCandy = 1; nowCandy <= candy - 2; nowCandy++) {
			ret += solve(index + 1, candy + nowCandy);
		}
	}
	else if (index == 1) {
		int nowCandy = n - candy;
		if (nowCandy > 0 && (nowCandy % 2) == 0) {
			return 1;
		}
	}

	return ret;
	
}

int main() {
	//freopen("input.txt", "r", stdin);
	n = 6;

	int ret = 0;

	
	for (int i = 1; i <= n; i++) {
		ret += solve(0, i);
	}

	cout << ret << endl;

	


	return 0;
}