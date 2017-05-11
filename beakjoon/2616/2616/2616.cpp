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

	int& ret = dp[train][num];

	if (ret != -1) return ret;

	if (num == 2) {
		return ret = nowClient[train];
	}

	ret = 0;
	
	for (int nextTrain = train + maxtrainNum; nextTrain <= trainNum - maxtrainNum * (2 - num); nextTrain++) {

		ret = max(ret, solve(nextTrain, num + 1) + nowClient[train]);

	}
	
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

	
	/*for (int i = 0; i < trainNum; i++) {
		cout << nowClient[i] << " ";
	}
	cout << endl;*/


	int ret = 0;

	for (int start = 0; start <= trainNum - 3 * maxtrainNum; start++) {
		ret = max(ret, solve(start, 0));
	}

	cout << ret << endl;

	cout << endl;

	for (int i = 0; i < trainNum; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}