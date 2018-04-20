#include <cstdio>
#include <algorithm>
using namespace std;

int uf[1000]; // union-find �迭

			  // union-find�� find ����
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

// union-find�� union ����
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

// ���� ����ü. w �������� ���ĵ�
struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator <(const Edge& O)const { return w < O.w; }
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	Edge e[100000];
	for (int i = 0; i<M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = Edge(a - 1, b - 1, c);
	}
	// ������ ����ġ �������� �������� ����
	sort(e, e + M);

	// result: ����ġ��, cnt: ���� ���� ��
	int result = 0, cnt = 0;
	fill(uf, uf + N, -1);
	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			result += e[i].w;
			if (++cnt == N - 1) break; // N-1�� ������ ������ ����
		}
	}
	printf("%d\n", result);
}

