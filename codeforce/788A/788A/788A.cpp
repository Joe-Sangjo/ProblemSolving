#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int arr[100100];

int pSum[100100];
int ppSum[100100];
int cand(int l, int r) {
	//2개의 차이가 홀수인지 짝수인지 체크.
	int diff = (r - l) % 2;

	int ret;
	//홀수 이면 : r의 범위를 1작게 만들고 +부분을 만든다.
	if (diff) {
		int plus = pSum[r - 1] - ((l == 0 || l == 1) ? 0 : pSum[l - 2]);
		int minus = pSum[r] - (l == 0 ? 0 : pSum[l - 2]);
		ret = plus - minus;
	}
	//짝수 이면
	else {
		int plus = pSum[r] - ((l == 0 || l == 1) ? 0 : pSum[l - 2]);
		int minus = pSum[r - 1] - (l == 0 ? 0 : pSum[l - 1]);
		ret = plus - minus;
	}
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		//cout << arr[i] << " ";
	}
	//cout << endl;
	if (N == 2) {
		cout << abs(arr[1] - arr[0]) << endl;
		return 0;
	}

	for (int i = 0; i < N - 1; i++) {
		arr[i] = abs(arr[i] - arr[i + 1]);
	}
	pSum[0] = arr[0]; pSum[1] = arr[1];
	for (int i = 2; i < N - 1; i += 2) {
		pSum[i] = pSum[i - 2] + arr[i];
		pSum[i + 1] = pSum[i - 1] + arr[i + 1];
	}

	/*for (int i = 0; i < N - 1; i++) {
		cout << pSum[i] << " ";
	}
	cout << endl;*/
	int ret = -0x3f3f3f3f;
	for (int l = 0; l < N - 1; l++) {
		for (int r = l; r < N - 1; r++) {
			ret = max(ret, cand(l, r));
		}
	}

	cout << ret << endl;

	return 0;
}