#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int K;
//입력 받을 숫자의 배열
vector<int> num;

void solve(vector<int> now, int index) {
	//기저사례
	if (now.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << now[i] << " ";
		}
		cout << endl;
		return;
	}


	for (int next = index + 1; next < K; next++) {
		now.push_back(num[next]);
		solve(now, next);
		now.pop_back();
	}

}
int main() {
	freopen("input.txt", "r", stdin);

	while (cin >> K) {
		//끝인 상황
		if (K == 0) break;

		num.clear();
		for (int i = 0; i < K; i++) {
			int temp; cin >> temp; num.push_back(temp);
		}

		for (int i = 0; i <= K - 6; i++) {
			vector<int> now; now.push_back(num[i]);
			solve(now, i);
		}
		cout << endl;


	}
	return 0;
}