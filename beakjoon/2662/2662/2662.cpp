#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int totalMoney, companyNum;

//invest[money][company] : money���� company���� �������� �� ���� �� �ִ� �ݾ�
int invest[301][20];



int dp[21][305];

//index�� ȸ�縦 ���� �� ��, remain�� ������ ���� �ִ� ����
int solve(int index, int remain) {
	// cout<<index<<" "<<remain<<endl;

	int& ret = dp[index][remain];

	//������� ������ȸ���� ��� ��� ���� ����Ѵ�.
	if (index == companyNum - 1) {
		return ret = invest[remain][index];
	}

	if (ret != -1) return ret;

	ret = 0;
	//���� indexȸ�翡�� nowInvest���� �����Ѵ�.
	for (int nowInvest = 0; nowInvest <= remain; nowInvest++) {
		ret = max(ret, solve(index + 1, remain - nowInvest) + invest[nowInvest][index]);
	}
	return ret;
}
//�� ����� �󸶾� �����ߴ��� ����Ѵ�.
vector<int> record;
void reconstruction(int index, int remain) {
	int comp = -1;
	int howMuch = 0;
	if (index == companyNum - 1) {
		howMuch = remain;
		record.push_back(howMuch);
	}
	else {
		for (int nowInvest = 0; nowInvest <= remain; nowInvest++) {
			if (comp < dp[index + 1][remain - nowInvest] + invest[nowInvest][index]) {
				comp = dp[index + 1][remain - nowInvest] + invest[nowInvest][index];
				howMuch =  nowInvest;
			}
		}
		record.push_back(howMuch);
		reconstruction(index + 1, remain - howMuch);
	}
	
	

}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> totalMoney >> companyNum;
	memset(dp, -1, sizeof(dp));
	memset(invest, 0, sizeof(invest));

	for (int i = 0; i < totalMoney; i++) {
		int nowMoney; cin >> nowMoney;
		for (int j = 0; j < companyNum; j++) {
			int m; cin >> m;
			invest[nowMoney][j] = m;
		}
	}
	// for(int i = 1; i <= totalMoney; i++){
	// 	for(int j = 0; j < companyNum; j++){
	// 		cout<<invest[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int ret = solve(0, totalMoney);

	cout << ret << endl;

	 /*for(int i = 0; i < companyNum; i++){
	 	for(int j = 0; j <= totalMoney; j++){
	 		cout<<dp[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }*/
	reconstruction(0, totalMoney);

	 for(int i = 0; i < record.size(); i++){
	 	cout<<record[i]<<" ";
	 }
	 cout<<endl;


	return 0;
}