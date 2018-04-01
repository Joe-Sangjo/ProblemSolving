#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>


using namespace std;

vector<vector<int> > adj;
int v, e;

//�� ������ ������Ʈ ��ȣ. ������Ʈ ��ȣ�� 0���� �����ϸ�
//���� ������ ������Ʈ�� ���� �������� ������Ʈ ��ȣ�� ����.
vector<int> sccId;

//�� ������ �߰� ����
vector<int> discovered;

//������ ��ȣ�� ��� ����
stack<int> st;

int sccCounter, vertextCounter;

//here�� root�� �ϴ� ����Ʈ������ ������ �����̳� ���� ������ 
//���� �� �� �ִ� ���� �� �ּ� �߰� ������ ��ȯ�Ѵ�.
//�̹� SCC�� ���� �������� ����� ���� ������ �����Ѵ�)
int scc(int here) {
	int ret = discovered[here] = vertextCounter++;

	//���ÿ� here�� �ִ´�. here�� �ļյ��� ��� ���ÿ��� here�Ŀ� ����.
	st.push(here);

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];

		//(here, there)�� Ʈ�� ����
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		//there�� �����ؾ��ϴ� ���� ������ �ƴ϶��
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}

	//here���� �θ�� �ö󰡴� ������ ����� ���� Ȯ���Ѵ�.
	if (ret == discovered[here]) {
		//here�� ��Ʈ�� �ϴ� ����Ʈ���� ���� �ִ� �������� ���� �ϳ��� ������Ʈ�� ���´�.
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		++sccCounter;
	}
	return ret;
}

//targan�� SCC�˰���
vector<int> tarjacSCC() {
	//�迭���� ���� �ʱ�ȭ
	sccId = discovered = vector<int>(adj.size(), -1);

	//ī���� �ʱ�ȭ
	sccCounter = vertextCounter = 0;

	//��� ������ ���� scc() ȣ��
	for (int i = 1; i < adj.size(); i++) if (discovered[i] == -1) scc(i);
	return sccId;

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &v, &e);

	adj = vector<vector<int> >(v + 1);

	
	for (int i = 0; i < e; i++) {
		int a, b; scanf("%d %d", &a, &b);

		adj[a].push_back(b);
	}

	vector<int> ret = tarjacSCC();

	cout << sccCounter << endl;

	vector<vector<int> > order(v + 1);
	int index = 0;
	for (int i = 0; i < sccId.size(); i++) {

	}



	return 0;
}