#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int arr[10001];
int pSumPlus[10001];
int pSumMinus[10001];
int n;
int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cout << arr[i] << " ";
	}
	

	for (int i = 0; i < n - 1; i++) {
		arr[i] = abs(arr[i] - arr[i + 1]);
	}

	pSumPlus[0] = arr[0], pSumMinus[0] = -pSumPlus[0];
	pSumPlus[1] = arr[1], pSumMinus[1] = -pSumPlus[1];


	//È¦¼ö
	for (int i = 3; i < n - 1; i += 2) {
		pSumPlus[i] = pSumPlus[i - 2] + arr[i - 2];
	}

	//Â¦¼ö


	return 0;
}