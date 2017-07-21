#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

typedef long long int ll;

using namespace std;


int n, m;
//friends[string] = string�̸��� ���� ������ ��ȣ
map<string, int> friends;

//foods[i][j] �� i�� ������ ���� �� �ִ� j��° ����. 
vector<pair<int, ll> > foods;

//��� ģ���� ������ �� �Ծ����� check
ll checkAllFrientAte;
//����
int best;


//����Ž��
//foodNumber Ž���ϴ� ������ ��ȣ
//numCookedFood �丮�� �� ������ ��
//checkEatableFriends ���ݱ��� ������ ���� ģ����(��Ʈ����ũ)
void brute_force(int foodNumber,  int numCookedFood, ll checkEatableFriends) {

	//�������
	//��� ģ���� �� ���� �� ������ -> ���� �ĺ�
	if (checkEatableFriends == checkAllFrientAte) {
		best = min(best, numCookedFood);
		return;
	}

	//��� �丮�� ��������, ��� ģ���� ���� �� ����. -> ���� �ȵ�
	if (foodNumber == m) {
		return;
	}

	//����ȭ.. ���� ���ĵ��� �� �Ծ �� ���̶� ���Դ� ��찡 �ִ� ��� �׳� ����

	//����ȭ.. ���ݱ��� �� ������ ���ڰ� best���� ũ�� �ǹ� ����
	if (numCookedFood >= best) return;
	//





	//foodNumber�� �丮�� �ϴ� ���
	ll EatableFriendsList = checkEatableFriends;
	EatableFriendsList |= foods[foodNumber].second;
	brute_force(foodNumber + 1, numCookedFood + 1, EatableFriendsList);


	//foodNumber�� �丮�� ���� �ʴ� ���
	brute_force(foodNumber + 1, numCookedFood, checkEatableFriends);


}
int main() {
	freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	//TC = 1;
	while (TC--) {
		//�ʱ�ȭ
		
		friends.clear(); foods.clear();

		cin >> n >> m;
		//ģ�� �̸� �Է�
		for (int i = 0; i < n; i++) {
			string temp; cin >> temp;
			friends[temp] = i;
		}
		
		int numDeleteFood = 0;
		//���� �Է�
		for (int i = 0; i < m; i++) {
			int num; cin >> num;
			int candFood = 0;
			for (int j = 0; j < num; j++) {
				string temp; cin >> temp;
				candFood |= (1 << friends[temp]);
			}

			bool checkExistence = true;
			for (int j = 0; j < foods.size(); j++) {
				if (foods[j].second == candFood) {
					checkExistence = false;
					break;
				}
			}
			//����ȭ.. ���� �� �ִ� ���̰� �Ȱ��� ������ ��� ���� -> Ž������ ���̱�
			if (!checkExistence) {
				numDeleteFood++;
			}
			else {
				foods.push_back(make_pair(-1 * __popcnt(candFood),candFood));
			}
		}

		m -= numDeleteFood;

		//����ȭ.. ������ ���� �� �ִ� ������ ����� ���� -> Ž������ �ٲٱ�
		sort(foods.begin(), foods.end());
		


		checkAllFrientAte = (1 << n) - 1;
		best = 0x3f3f3f3f;

		/*for (int i = 0; i < foods.size(); i++) {
			for (int j = 0; j < foods[i].size(); j++) {
				cout << foods[i][j] << " ";
			}
			cout << endl;
		}*/

		brute_force(0, 0, 0);
		

		cout << best << endl;

		

	}
	return 0;
}