#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int coverType[4][3][2] ={ 
	{{0,0}, {1,0} ,{0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
	};
vector<vector<int> > board;
int H, W;
int recur = 0;
bool set(vector<vector<int> >& board, int y, int x, int type, int delta){
	bool ok = true;
	
	for(int i = 0; i < 3; i++){
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}
int cover(vector<vector<int> >& board) {
	recur ++;
	int y = -1, x = -1;
	for(int i = 0 ; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++){
			if(board[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1 ) break;
	}
	if(y == -1 ) return 1;
	int ret = 0;
	for(int type = 0; type < 4 ; type++){
		if(set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	cin>>T;
	char in;
	for(int test_case=0; test_case<T;test_case++){
		cin>>H>>W;

   		for(int i = 0; i < H ; i++){
   			board.push_back(vector<int>());
   		}
   		for(int i = 0; i < H ; i++){
   			for(int j = 0 ; j < W ; j++){
   				cin>>in;
   				if(in == '#')
   					board[i].push_back(1);
   				else
   					board[i].push_back(0);
   			}
   		}
   		// for(int i = 0; i < board.size() ; i++){
   		// 	for(int j = 0; j < board[i].size(); j++){
   		// 		cout<<board[i][j]<<" ";
   		// 	}
   		// 	cout<<endl;
   		// }
   		// cout<<endl;
   		cout<<cover(board)<<endl;
   		for(int i = 0 ; i < H ; i ++){
   			for(int j = 0; j < W; j++){
   				board[i].pop_back();
   			}
   		}
   		for(int i = 0; i < H ; i++){
   			board.pop_back();
   		}
	}
	cout<<endl<<endl<<recur<<endl;
	return 0;
}
