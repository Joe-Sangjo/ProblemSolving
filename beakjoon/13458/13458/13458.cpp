#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int N;
vector<int> A;
int B, C;

int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		A.push_back(temp);
	}
	cin >> B >> C;

	long long ret = N;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] <= 0) {
			continue;
		}
		else {
			int remain = A[i] % C;
			int div = A[i] / C;
			ret += (remain == 0) ? div : div + 1;
		}
	}

	cout << ret << endl;
	return 0;
}