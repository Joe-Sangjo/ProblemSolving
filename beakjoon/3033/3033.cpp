#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 200010;
string input;

//group : �׷� ��ȣ
int N, d, group[MAX];

vector<int> SA;
vector<int> LCP;

//���̻� �񱳿� ����� �� �Լ�
bool cmp(int i, int j) {
	//���� �ڽ��� ��ġ�� ���ڸ� ��
	if (group[i] != group[j]) return group[i] < group[j];
	//���ڰ� ������ dĭ ���� ���ڳ��� ��
	i += d;
	j += d;
	return (i < N && j < N) ? (group[i] < group[j]) : (i > j);
}

//S�� ����� sa �迭�� ����� �Լ�
vector<int> getSuffixArray() {

	//��ó��
	for (int i = 0; i < N; i++) {
		SA[i] = i;
		group[i] = input[i]; //���� ù ���� ���������� ���ڸ� ���ڷ� ��
	}

	//d�� 2�辿 �÷����鼭 �Ź� �տ������� d*2���ڸ� ���� ���̻� ����
	for (d = 1; ; d *= 2) {
		sort(SA.begin(), SA.end(), cmp);
		//newGroup : ���ο� �׷� ��ȣ
		vector<int> newGroup(N);
		//�տ������� �����鼭 �� ���̻簡 ���� �ٸ� �׷쿡 ���Ҷ����� �׷� ��ȣ ������Ŵ
		for (int i = 0; i < N - 1; i++)
			newGroup[i + 1] = newGroup[i] + cmp(SA[i], SA[i + 1]);
		//group�迭�� newGroup �迭�� ��ü
		for (int i = 0; i < N; i++)
			group[SA[i]] = newGroup[i];

		//��� ���̻簡 �ٸ� �׷����� ���������ٸ� ����
		if (newGroup[N - 1] == N - 1) break;
	}
	return SA;
}

//SA�� �־����� LCP�� ����� �Լ�
void getLCP() {

	//group[i] = S[i:]�� SA�� �� ��°�� �ִ°�(group[SA[i]] = i)
	//���� �� ���̻�(S)���� �����Ѵ�.
	//�� �������� k > 0 �̸�  k--
	for (int i = 0, k = 0; i < N; i++, k = max(k - 1, 0)) {

		//������ ���̻�(���� 1)�� �ƹ��͵� ����
		if (group[i] == N - 1) continue;

		//�ٷ� �Ʒ� ������ ���̻�� ���Ͽ� �տ��� ���� �� ���� ���ڰ� 
		//��ġ�ϴ��� ����
		for (int j = SA[group[i] + 1]; input[i + k] == input[j + k]; k++);

		LCP[group[i]] = k;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> N;
	cin >> input;
	SA = vector<int>(N);
	LCP = vector<int>(N - 1);

	getSuffixArray();

	//for (int i = 0; i < SA.size(); i++) {
	//	for (int j = SA[i]; j < N; j++)
	//		cout << input[j];
	//	cout << endl;
	//}


	getLCP();
	int ret = 0;
	for (int i = 0; i < LCP.size(); i++) {
		ret = max(ret, LCP[i]);
	}
	cout << ret << endl;

}

