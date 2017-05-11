#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define max(a, b) a > b ? a : b

int trainNum;
int clientNum[50001];
int nowClient[50001];

int maxtrainNum;

int dp[50001][3];


//몇번 기차에 몇 번 째 소형 기관차
int solve(int train, int num) {
	//cout << train << " " << num << endl;
	if (train >= trainNum) return 0;

	int& ret = dp[train][num];

	if (ret != -1) return ret;

	if (num == 2) {
		return ret = max(nowClient[train], solve(train + 1, num));
	}

	ret = 0;

	ret = max(solve(train + maxtrainNum, num + 1) + nowClient[train], solve(train + 1, num));
	
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> trainNum;
	for (int i = 0; i < trainNum; i++) {
		cin >> clientNum[i];
		//cout << clientNum[i] << endl;
	}
	cin >> maxtrainNum;
	
	memset(dp, -1, sizeof(dp));

	if (trainNum <= 3) {
		int ret = 0;
		for (int i = 0; i < trainNum; i++) {
			ret += clientNum[i];
		}
		cout << ret << endl;
		return 0;
	}



	int TToing = 0; 
	for (int i = 0; i < maxtrainNum; i++) {
		TToing += clientNum[i];
	}

	nowClient[0] = TToing;

	for (int i = 1; i <= trainNum - maxtrainNum; i++) {
		TToing -= clientNum[i - 1];
		TToing += clientNum[i - 1 + maxtrainNum];
		nowClient[i] = TToing;
	}

	int ret = 0;

	for (int start = 0; start <= trainNum - 3 * maxtrainNum; start++) {
		ret = max(ret, solve(start, 0));
	}

	cout << ret << endl;

	return 0;
}