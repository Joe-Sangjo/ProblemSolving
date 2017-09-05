#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int k;
vector<int> sizeOfFile;



int best;

void solve(int nowCost, vector<int>& remainSizeOfFile) {

	cout << nowCost << endl;
	for (int i = 0; i < remainSizeOfFile.size(); i++) {
		cout << remainSizeOfFile[i] << " ";
	}
	cout << endl << endl;
	//�������	
	if (remainSizeOfFile.size() == 1) {
		best = max(best, nowCost);
		return;
	}

	//������ ��ģ��. ������ �� 2��
	int n = remainSizeOfFile.size();

	int End = remainSizeOfFile[n - 1]; int EndtoEnd = remainSizeOfFile[n - 2];

	remainSizeOfFile.pop_back(); remainSizeOfFile.pop_back();
	
	nowCost += (End + EndtoEnd);

	remainSizeOfFile.push_back(End + EndtoEnd);
	
	sort(remainSizeOfFile.begin(), remainSizeOfFile.end());

	//����Ѵ�.
	solve(nowCost, remainSizeOfFile);

	//�����Ѵ�.
	remainSizeOfFile.pop_back();

	remainSizeOfFile.push_back(EndtoEnd); remainSizeOfFile.push_back(End);

}
int main() {
	freopen("input.txt", "r", stdin);

	int TC; cin >> TC;

	while (TC--) {

		cin >> k;
		
		sizeOfFile.resize(k);

		for (int i = 0; i < k; i++) {
			cin >> sizeOfFile[i];
			//vector�� ���� ���� -1�� ���Ѵ�. pop_back	
			sizeOfFile[i] *= -1;
		}

		//1. ������ �ٲ۴�.
		sort(sizeOfFile.begin(), sizeOfFile.end());

		for (int i = 0; i < k; i++) {
			cout << sizeOfFile[i] << " ";
		}
		cout << endl;
		
		best = -0x3f3f3f3f;

		solve(0, sizeOfFile);

		cout << -best << endl;

		//2. ����� �صд�.


		//3. 

	}


	return 0;
}