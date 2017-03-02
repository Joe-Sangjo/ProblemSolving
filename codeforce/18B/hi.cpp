#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

bool board[2601][2601][4];
//동 남 서 북
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,-1, 0,1};
int changeDir(char d, int now){
	int ret = now;
	if(d == 'L'){
		ret--;
	
	}else if(d =='R'){
		ret++;
	}
	ret += 4;
	ret %= 4;
	return ret;
}
bool checkInBound(int x, int y){
	return x <= 2501 && x >=0 && y <=2501 && y >= 0;
}
vector < string > doesCircleExist(vector < string > commands) {
	vector<string> ret;
	for(int TC = 0; TC < commands.size(); TC++){
		memset(board, false, sizeof(board));

		string now =commands[TC];
		int dir = 3;
		int x = 0, y = 0;
		board[x][y][dir] = true;
		bool result = true;
		for(int i = 0; i < now.size() - 1; i++){
			if(now[i] == 'G'){
				x += dx[dir]; y+= dy[dir];
				if(!checkInBound(x, y)){
					result = false;
					break;
				}
				board[x][y][dir] = true;
			}
			else{
				dir = changeDir(now[i], dir);
				x += dy[dir]; y +=dy[dir];
				if(!checkInBound(x, y)){
					result = false;
					break;
				}
				board[x][y][dir]= true;
			}
		}
		if(now[now.size()-1] == 'G'){
			x += dx[dir]; y+= dy[dir];
			if(!checkInBound(x, y)){
				result = false;
			}
		}
		else{
			dir = changeDir(now[now.size()-1], dir);
			x += dy[dir]; y +=dy[dir];
			if(!checkInBound(x, y)){
				result = false;
			}
		}
		result = board[x][y][dir];
		if(result){
			ret.push_back("YES");
		}
		else{
			ret.push_back("NO");
		}
	}
	return ret;
}
int main(){

	int n = 2;
	vector<string> in;
	in.push_back("G");
	in.push_back("L");
	vector<string> ret = doesCircleExist(in);
	for(int i = 0; i < ret.size(); i++){
		cout<<ret[i]<<endl;
	}
	return 0;
}