#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int cache[1<<25][2];
int dir[6][3][2] = { 
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{1,0}},
	{{0,0},{0,1}}
};
int bijection(vector<string>& board);
int block(vector<string>& board, int turn);
bool printing(vector<string>& board, int y, int x, int n, char what);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		string buf;
		vector<string> board;
		for(int i = 0; i < 5; i++){
			cin>>buf;
			board.push_back(buf);
		}
		memset(cache, -1, sizeof(cache));
		if(block(board, 0)){
			cout<<"WINNING"<<endl;
		}
		else{
			cout<<"LOSING"<<endl;
		}
	}

	return 0;
}
int bijection(vector<string>& board){
	int ret = 0;
	for(int y = 0 ; y < 5; y++){
		for(int x = 0; x < 5; x++){
			ret *= 2;
			if(board[y][x] == '#') ret++;
		}
	}
	return ret;
}
bool printing(vector<string>& board, int y, int x, int n, char what){
	if(what == '#'){
		if(!(n == 4 || n == 5)){
			for(int i = 0; i < 3; i++){
				if(!(y + dir[n][i][0] > 4 || y + dir[n][i][0] < 0 || x + dir[n][i][1] > 4 || x + dir[n][i][1] < 0 || board[y + dir[n][i][0]][x + dir[n][i][1]] == '#') )
					board[y + dir[n][i][0]][x + dir[n][i][1]] = what;
				else{
					return false;
				}
			}		
		}
		else{
			for(int i = 0; i < 2; i++){
				if(!(y + dir[n][i][0] > 4 || y + dir[n][i][0] < 0 || x + dir[n][i][1] > 4 || x + dir[n][i][1] < 0 || board[y + dir[n][i][0]][x + dir[n][i][1]] == '#') )
					board[y + dir[n][i][0]][x + dir[n][i][1]] = what;
				else{
					return false;
				} 
			}
		}
		return true;
	}
	else{
		if( !(n == 4 || n == 5)){
			for(int i = 0; i < 3; i++){
				board[y + dir[n][i][0]][x + dir[n][i][1]] = what;
			}
		}
		else{
			for(int i =0 ; i < 2; i++){
				board[y+dir[n][i][0]][x + dir[n][i][1]] = what;
			}
		}
	}
}
int block(vector<string>& board, int turn){

	int& ret = cache[bijection(board)][turn];

	if(ret != -1) return ret;

	if(turn == 1){
		ret = 987654321;
		for(int y = 0; y < 5; y++){
			for(int x = 0; x < 5; x++){
				for(int j = 0; j < 6; j++){
					if(printing(board, y, x, j, '#')){
						int cand = block(board, 0);
						if(cand == 1)
							ret = min(ret, 0);
						else
							ret = min(ret, 1);
						printing(board, y, x, j, '.');
					}
				}
			}
		}
	}
	else{		
		for(int y = 0; y < 5; y ++){
			for(int x = 0; x < 5; x++){
				for(int j = 0; j < 6; j++){
					if(printing(board, y, x, j, '#')){
						int cand = block(board, 1);
						if(cand == 1)
							ret = max(ret, 0);
						else
							ret = max(ret, 1);
						printing(board, y, x, j, '.');
					}
				}
			}
		}

	}
	return ret;
}