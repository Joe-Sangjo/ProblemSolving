#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K, M, L;

//��������
int prerequisite[13];

//������ ����
int openLecture[11];

//dp[�б�][��������]
int dp[11][1 << 12];

//semester �б⿡ takenLecture �б⸦ ����ٸ�
int solve(int semester, int takenLecture) {

	//��������  K���� �� ����ٸ�. �������
	if (__popcnt(takenLecture) == K) return 1;

	int& ret = dp[semester][takenLecture];
	
	if (ret != -1) return ret;

	ret = 0x3f3f3f3f;

	//���� �б⿡ ���� ������� ���� �� �� ����!
	for (int subject = openLecture[semester]; subject; subject = ((subject - 1) & openLecture[semester])) {
		//subject�� �� bit�� ���� ����.


		//���� �� �ִ� ������ ���� check!
		if (__popcnt(subject) > L) continue;

		bool possible = true;
		//���� ������� ���鼭 ���������� check!
		for (int j = 0; j < N; j++) {
			//openLecture[j]�� takenLecture�� �κ������� �ƴϸ�
			if ((openLecture[j] & takenLecture) != openLecture[j]) {
				possible = false;
				break;
			}

			//j��° ������ �̹� ����ٸ� pass!
			if (takenLecture & (1 << j)) {
				possible = false;
				break;
			}
		}

		//�����ϸ�,
		if (possible) {
			ret = min(ret, solve(semester + 1, takenLecture | subject) + 1);
		}

	}
	//�̹��б� �� �������� ���ݾ�
	ret = min(ret, solve(semester + 1, takenLecture));

	return ret;
}

int main() {

	freopen("input.txt", "r", stdin);


	int TC; cin >> TC;

	while (TC--)
	{
		cin >> N >> K >> M >> L;

		memset(prerequisite, 0, sizeof(prerequisite));
		memset(openLecture, 0, sizeof(openLecture));
		memset(dp, -1, sizeof(dp));

		#pragma region �Է�ó��


		for (int i = 0; i < N; i++) {
			int R;
			cin >> R;
			for (int j = 0; j < R; j++) {
				int subject; cin >> subject;
				prerequisite[i] &= (1 << subject);
			}
		}
		for (int semester = 0; semester < M; semester++) {
			int subjectNumber; cin >> subjectNumber;
			for (int index = 0; index < subjectNumber; index++) {
				int subject; cin >> subject;
				openLecture[semester] &= (1 << subject);
			}
		}
		#pragma endregion

		int ret = solve(0, 0);

		if (ret == -1) cout << "IMPOSSIBLE" << endl;
		else cout << ret << endl;

	
	}

	return 0;
}