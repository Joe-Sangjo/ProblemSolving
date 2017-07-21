#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX 1000*1000*10

using namespace std;

int n,lo, hi;

//minFactor[i] = i �� ���� ���� ���μ�
int minFactor[MAX + 1];

//minFactorPower[i] = i�� ���μ� ���ؿ��� minFactor[i]�� �� ���� ���ԵǾ� �ִ°�?
int minFactorPower[MAX + 1];

//factors[i] = i �� ���� ����� ��
int factors[MAX + 1];

void eratosthenes2() {
	minFactor[0] = minFactor[1] = -1;
	n = MAX;
	for (int i = 2; i <= n; i++) {
		minFactor[i] = i;
	}
	int sqrtn = int(sqrt(n));

	for (int i = 2; i <= sqrtn; i++) {
		//�Ҽ��� ���
		if (minFactor[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				//�Ҽ��� ���. �� �ռ��� �� ��� ���� ���� ���μ��� �����Ѵ�.
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}


void getFactorsSmart() {
	factors[1] = 1;
	for (int n = 2; n <= MAX; n++) {
		
		if (minFactor[n] == n) {
			minFactorPower[n] = 1;
			factors[n] = 2;
		}
		else {
			int p = minFactor[n];
			int m = n / p;

			if (p != minFactor[m])
				minFactorPower[n] = 1;
			else
				minFactorPower[n] = minFactorPower[m] + 1;
			int a = minFactorPower[n];

			factors[n] = (factors[m] / a) * (a + 1);
		}
	}
}

void getFactorsBrute() {
	memset(factors, 0, sizeof(factors));
	for (int div = 1; div <= MAX; div++)
		for (int multiple = div; multiple <= MAX; multiple += div)
			factors[multiple] ++;
}
int main() {

	freopen("input.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	
	//�����佺�׳׽��� ü�� �̿��Ͽ� ���� ���� ���μ��� ����
	eratosthenes2();


	//����� ������ ����
	//factor(n) = factor(n/p) * ((a+1)/a)
	//getFactorsSmart();
	getFactorsBrute();


	while (TC--) {
		scanf("%d%d%d", &n, &lo, &hi);

		//cout << n << " " << lo << " " << hi << endl;
		int Count = 0;
		
		for (int i = lo; i <= hi; i++) {
			Count += (factors[i] == n);
		}

		printf("%d\n", Count);
	}
	return 0;
}