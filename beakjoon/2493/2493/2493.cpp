#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

#define mp make_pair

using namespace std;


int N;
vector<int> building;
int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		building.push_back(temp);
	}

	vector<int> result = vector<int>(N, 0);
	/*for (int i = 0; i < N; i++) {
		cout << result[i] << endl;
	}*/

	stack<pair<int, int> > st;

	for (int i = N - 1; i >= 0; i--) {

		//스택이 비었을 때 -> 그냥 쌓기만 한다.
		if (st.empty()) {
			st.push(mp(building[i],i));
		}
		//stack이 안비었을 때,
		else {
			int hereHeight = building[i];
			int here = i;
			while (!st.empty()){
				int beforeH = st.top().first;
				int before = st.top().second;

				if (hereHeight > beforeH) {
					result[before] = here + 1;
					st.pop();
				}
				else {
					break;
				}
			}

			st.push(mp(building[i], i));
		}
	}
	while (!st.empty())
	{
		int before = st.top().second;
		result[before] = 0;
		st.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	return 0;
}