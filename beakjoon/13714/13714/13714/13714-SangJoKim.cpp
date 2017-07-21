#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


//�����佺�׳׽��� ü�� �̿��Ͽ� Prime�� 2000������ �Ҽ��� ���� �ִ´�. 
//�� �Ҽ��� ������ 303��
bool isPrime[2001];
vector<int> Prime;



//2000������ ���� ���μ� �����Ͽ� �� �Ҽ��� ��� �̷�������� �����Ѵ�.
//numOfPrimeFactor[i][j] = i�� ���μ������ϸ� Prime[j]�� �?
int numOfPrimeFactor[2001][304];


int nowPrimeFactor[303];

void incresePrimeFactor(int i) {

	for (int idx = 0; idx < 303; idx++) {
		nowPrimeFactor[idx] += numOfPrimeFactor[i][idx];
	}

}

void decreasePrimeFactor(int i) {

	for (int idx = 0; idx < 303; idx++) {
		nowPrimeFactor[idx] -= numOfPrimeFactor[i][idx];
	}

}
int main() {
	

	#pragma region Rrime�� �Ҽ��� ������ ���� ����
	//Prime�� �Ҽ��� ������ ���� �ִ´�.
	memset(isPrime, true, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= 2000; i++) {
		for (int j = i * i; j <= 2000; j += i) {
			isPrime[j] = false;
		}
	}

	for (int i = 0; i <= 2000; i++) {
		if (isPrime[i])
			Prime.push_back(i);
	}

	#pragma endregion

	//cout << Prime.size() << endl;

	#pragma region numOfPrimeFactor�� ���μ��� ������ �ִ´�.

	memset(numOfPrimeFactor, 0, sizeof(numOfPrimeFactor));

	for (int i = 2; i <= 2000; i++) {
		int now_I = i;
		for (int j = 0; j < Prime.size(); j++) {
			int count = 0;

			//������ ��������
			while (now_I % Prime[j] == 0) {
				now_I /= Prime[j];
				count++;
			}

			//�� ������ ����������
			numOfPrimeFactor[i][j] = count;
		}
	}


	////test
	//for (int i = 0; i < 10; i++) {
	//	printf("%4d", Prime[i]);
	//}
	//cout << endl << endl;

	//for (int i = 0; i < 10; i++) {
	//	printf("%4d", numOfPrimeFactor[100][i]);
	//}
	//cout << endl;
	


	#pragma endregion


	#pragma region ����� ������ ���� ��� ���Ѵ�

	int ret = 0;
	freopen("input.txt", "r", stdin);

	int a, b, c; cin >> a >> b >> c;


	

	for (int i = 1; i <= a; i++) {

		incresePrimeFactor(i);

		for (int j = 1; j <= b; j++) {

			incresePrimeFactor(j);

			for (int k = 1; k <= c; k++) {

				incresePrimeFactor(k);

				int nowNumOfFactor = 1;

				for (int index = 0; index < 303; index++) {
					if (nowPrimeFactor[index] > 0) {
						nowNumOfFactor *= nowPrimeFactor[index] + 1;
					}
				}

				ret += nowNumOfFactor;

				decreasePrimeFactor(k);
			}
			decreasePrimeFactor(j);
		}
		decreasePrimeFactor(i);
	}
	#pragma endregion


	cout << ret << endl;


	return 0;
}