#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1001;
string input;

//group : �׷� ��ȣ
int N, d, group[MAX];

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

	vector<int> sa(N);
	//��ó��
	for (int i = 0; i < N; i++) {
		sa[i] = i;
		group[i] = input[i]; //���� ù ���� ���������� ���ڸ� ���ڷ� ��
	}

	//d�� 2�辿 �÷����鼭 �Ź� �տ������� d*2���ڸ� ���� ���̻� ����
	for (d = 1; ; d *= 2) {
		sort(sa.begin(), sa.end(), cmp);
		//newGroup : ���ο� �׷� ��ȣ
		vector<int> newGroup(N);
		//�տ������� �����鼭 �� ���̻簡 ���� �ٸ� �׷쿡 ���Ҷ����� �׷� ��ȣ ������Ŵ
		for (int i = 0; i < N - 1; i++) 
			newGroup[i + 1] = newGroup[i] + cmp(sa[i], sa[i + 1]);
		//group�迭�� newGroup �迭�� ��ü
		for (int i = 0; i < N; i++) 
			group[sa[i]] = newGroup[i];

		//��� ���̻簡 �ٸ� �׷����� ���������ٸ� ����
		if (newGroup[N - 1] == N - 1) break;
	}
	return sa;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> input;
	N = input.size();
	vector<int> sa = getSuffixArray();

	for (int i = 0; i < sa.size(); i++) {
		for (int j = sa[i]; j < N; j++)
			cout << input[j];
		cout << endl;
	}

}

