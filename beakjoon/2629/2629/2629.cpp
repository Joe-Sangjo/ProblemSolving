#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int sum;
vector<int> cho;

int dp[31][30010];

//무게와 dp의 index상의 변환
// -15000 <= w <=15000
// index = w + 15000 / -15000 -> 0, 0 ->15000, 15000 -> 30000
int weightToIndex(int w) {
	return w + 15000;
}
int IndextToWeight(int i) {
	return i - 15000;
}
bool globalCheck;
int solve(int here, int w) {
	//cout << here << " " << w << endl;
	//무게의 합이 0 : 내가 원하는 경우
	if (w == 0) {
		return 0;
	}
	//모든 경우를 확인한 경우
	if (here >= n) return 0x3f3f3f3f;
	//이미 가능한 경우가 있는 경우
	//if (globalCheck) return;

	int& ret = dp[here][abs(w)];

	if (ret != -1) return ret;

	ret = 0x3f3f3f3f;
	
	int temp;
	//모든 추의 합보단 클 필요는 없다.
	if (w <= sum) {
		temp = solve(here + 1, abs(w - cho[here]));
		ret = temp == 0 ? 0 : 0x3f3f3f3f;
	}
	
	if (ret != 0) {
		temp = solve(here + 1, w);
		ret = temp == 0 ? 0 : 0x3f3f3f3f;
	}
	//모든 추의 합보단 작을 필요는 없다.
	if (ret != 0) {
		temp = solve(here + 1, w + cho[here]);
		ret = temp == 0 ? 0 : 0x3f3f3f3f;
	}

	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		cho.push_back(temp);
		sum += temp;
	}
	cin >> m;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < m; i++) {
		int weight; cin >> weight;
		if (weight > sum) {
			cout << 'N' << " ";
			continue;
		}

		globalCheck = false;

		int ret = solve(0, weight);
		if (ret == 0) {
			cout << "Y" << " ";
		}
		else {
			cout << "N" << " ";
		}
	}

	return 0;
}