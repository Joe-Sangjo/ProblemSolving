#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<string> map;

int cnt;

//오른쪽과 아랫쪽으로만 이동할꺼임
void solve(int y, int x,vector<char> princess) {
	if (princess.size() == 7) {
		int Scnt = 0;
		for (int i = 0; i < 7; i++) {
			Scnt += princess[i] == 'S';
		}
		cnt += Scnt >= 4;
		if (Scnt >= 4) {
			cout << "!!!!!!!!!!!" << endl;
		}
		return;
	}

	//오른쪽으로
	if (x < 4) {
		princess.push_back(map[y][x + 1]);
		solve(y, x + 1, princess);
		princess.pop_back();
	}
	//아랫쪽으로
	if (y < 4) {
		princess.push_back(map[y + 1][x]);
		solve(y + 1, x, princess);
		princess.pop_back();
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	string temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp; map.push_back(temp);
		//cout << temp << endl;
	}
	cnt = 0;
	vector<char> princess;
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		//princess.push_back(map[i][j]);
	//		//solve(i, j, princess);
	//		//princess.pop_back();
	//	}
	//}
	princess.push_back('S');
	solve(1, 0, princess);
	cout << cnt << endl;

	return 0;
}