#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//�־����� �Է�, Height, With, Row, Col
int H, W, R, C;
//������
vector<string> board;
//���
vector<string> block;
//��ϵ�
vector<vector<string> > blocks;
//����
int ans;


//90�� ȸ��
vector<string> changeDir(vector<string>& block) {
	
	vector<string> tempBlock(block[0].size(), string(block.size(),' '));

	for (int i = 0; i < block.size(); i++) {
		for (int j = 0; j < block[0].size(); j++) {
			tempBlock[j][block.size() - i - 1] = block[i][j];
		}
	}

	return tempBlock;
}

//��ϰ� ����� 90�� ȸ����Ų 3������ ��ȯ�Ѵ�
vector<vector<string> > makeNinetyDegreeRotate(vector<string>& block) {

	vector<vector<string> > ret;
	ret.push_back(block);
	
	for (int i = 0; i < 3; i++) {
		block = changeDir(block);
		ret.push_back(block);
	}
	
	return ret;
}

//���忡 ����� �д�
bool placeBlock(int y, int x, int index) {

	for (int i = 0; i < blocks[index].size(); i++) {
		if (y + i >= H) return false;

		for (int j = 0; j < blocks[index][i].size(); j++) {

			if (x + j >= W) return false;
			
			if (blocks[index][i][j] == '#') {
				if(board[y + i][x + j] == '.') {
					board[y + i][x + j] = '#';
				}
				else {
					return false;
				}
			}
		}
	}

	return true;
}


//���忡 �ξ��� ����� ������
void unplaceBlock(int y, int x, int index) {


	for (int i = 0; i < blocks[index].size(); i++) {

		if (y + i >= H) return;

		for (int j = 0; j < blocks[index][i].size(); j++) {

			if (x + j >= W) return;

			if (blocks[index][i][j] == '#') {
				if (board[y + i][x + j] == '#') {
					board[y + i][x + j] = '.';
				}
				else {
					return;
				}
			}
		}
	}
}

void show() {
	for (int i = 0; i < board.size(); i++) {
		cout << board[i] << endl;
	}
	cout << endl;
}

//����Ž��
void brute_force(int num) {

	show();

	ans = max(ans, num);

	int y = -1, x = -1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != '#') {
				y = i, x = j;
			}
		}
		if (y != -1) break;
	}

	if (y == -1) return;


	for (int i = 0; i < 4; i++) {

		if (placeBlock(y, x, i)) {
			brute_force(num + 1);
		}
		
		unplaceBlock(y, x, i);

	}

}


int main() {

	freopen("input.txt", "r", stdin);

	int TC; cin >> TC;

	while (TC--) {

		board.clear(); block.clear(); blocks.clear();
		ans = -1;

		cin >> H >> W >> R >> C;

		for (int i = 0; i < H; i++) {
			string temp; cin >> temp;
			board.push_back(temp);
			//cout << temp << endl;
		}

		for (int i = 0; i < R; i++) {
			string temp; cin >> temp;
			block.push_back(temp);
			//cout << temp << endl;
		}


		blocks = makeNinetyDegreeRotate(block);

		/*for (int i = 0; i < blocks.size(); i++) {
			for (int j = 0; j < blocks[i].size(); j++) {
				cout << blocks[i][j] << endl;
			}
			cout << endl << endl;
		}*/
		brute_force(0);


		cout << ans << endl;

	}

	return 0;
}