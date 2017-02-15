#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;
int H, W, R, C;
vector<string> board;
vector<vector<pair<int, int> > > ro;
vector<string> rotation(vector<string>& block);
int best;
void brute_force(vector<string>& board);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>H>>W>>R>>C;

		board.clear();

		vector<string> block;

		string buf;
		for(int i = 0; i < H; i++){
			cin>>buf;
			board.push_back(buf);
		}
		
		for(int i = 0; i < R; i++){
			cin>>buf;
			block.push_back(buf);
		}
		for(int i = 0; i < 4; i++){
			vector<pair<int, int> > temp;
			// for(int y = 0; y < block.size(); y++){
			// 	for(int x = 0; x < block[0].size(); x++){
			// 		cout<<block[y][x]<<" ";
			// 	}
			// 	cout<<endl;
			// }
			// cout<<endl;
			for(int y = 0; y < R; y++){
				for(int x = 0 ; x < C; x++){
					if(block[y][x] == '#'){
						temp.push_back(make_pair(y,x));
					}
				}
			}
			ro.push_back(temp);
			block = rotation(block);
		}
		best = 0;
		brute_force(board);

	}

	return 0;
}

vector<string> rotation(vector<string>& block){

	vector<string> temp(block[0].size(), string(block.size(), ' '));
	for(int i = 0; i < block.size(); i++){
		for(int j = 0 ; j < block[0].size(); j++){
			temp[j][block.size() - i - 1] = block[i][j];
		}
	}
	return temp;
}

void brute_force(vector<string>& board){
	int xx = yy = -2;
	for(int y = 0 ; y < H; y++){
		for(int x = 0; x < W; x++){
			if(board[y][x] == '.'){
				xx = x; yy = y;
				break;
			}
		}
	}

	if(y == -2){
		best = max(best, );
		return;
	}
	for(int i = 0; i < ro.size(); i++){
		if(cover(y, x, board, ro[i])){
			
			brute_force(board);
			
			reversecover(y, x, board, ro[i]);
		}
	}




}
