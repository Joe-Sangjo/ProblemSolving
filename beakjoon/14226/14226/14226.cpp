#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;


//visited[i][j] 
// i : ���� ȭ���� �̸�Ƽ�� ����
// j : Ŭ�� ���忡 ����� �̸�Ƽ���� ����
int visited[2010][2010];
int s;
queue<pair<int, int> > q;

int main() {
	
	cin>>s;

	memset(visited, -1, sizeof(visited));

	//����.
	q.push(make_pair(1, 0));
	visited[1][0] = 0;

	int ret; 

	while (!q.empty()) {

		int nowView = q.front().first;
		int nowClib = q.front().second;
		q.pop();
		int nowDist = visited[nowView][nowClib];
		if (nowView == s) {
			ret = nowDist;
			break;
		}


		//Ŭ�����忡 ����
		if (visited[nowView][nowView] == -1) {
			q.push(make_pair(nowView, nowView));
			visited[nowView][nowView] = nowDist + 1;
		}

		//Ŭ�����忡 �ִ� �̸�Ƽ�� �ٿ��ֱ�
		if ((nowView + nowClib) <= 2000 && visited[nowView + nowClib][nowClib] == -1) {
			q.push(make_pair(nowView + nowClib, nowClib));
			visited[nowView + nowClib][nowClib] = nowDist + 1;
		}

		//�̸�Ƽ�� �ϳ� ����
		if ((nowView - 1) >= 0 && visited[nowView - 1][nowClib] == -1) {
			q.push(make_pair(nowView - 1, nowClib));
			visited[nowView - 1][nowClib] = nowDist + 1;
		}
	}

	cout << ret << endl;

	return 0;
}