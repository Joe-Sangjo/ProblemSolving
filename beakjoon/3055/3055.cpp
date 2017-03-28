#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int r, c;
//D가 목표 S가 고슴도치.
int d_y, d_x;
int s_y, s_x;


//안쪽이면 true;
bool isIn(int y, int x){
	return y < r && y >= 0 && x < c && x >= 0;
}

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int minMove = 3000;


void printMap(vector<string> map){
	for(int i = 0; i < map.size(); i++){
		cout<<map[i]<<endl;
	}
	cout<<endl;
}
//갔던 곳에 다시 갈 필요는 없지 안느냐?
//갔으면 true, 안갔으면 false
bool visited(const vector<pair<int, int> >& path, int nowY, int nowX){

	for(int i = 0; i < path.size(); i++){
		if(path[i].first == nowY && path[i].second == nowX){
			return true;
		}
	}
	return false;
}
void moving(vector<string> map, int nowSy, int nowSx, int nowMove, vector<pair<int, int> > path){
	//기저사례 끝내기
	if(nowMove >= minMove) return;
	//기저사례 고슴토치가 굴로 들어감
	if(nowSy == d_y && nowSx == d_x){
		minMove = min(minMove, nowMove);
		return;
	}

	//이미 갔던 곳 갈필요 없잖아?
	if(visited(path, nowSy, nowSx)){
		return;
	}
	path.push_back(make_pair(nowSy, nowSx));


	map[nowSy][nowSx] = 'S';
	// printMap(map);
	//물이 있는 곳 근처에 물이 생겨야함
	vector<pair<int, int> >MUL;
	for(int y = 0; y < r; y++){
		for(int x = 0; x < c; x++){
			if(map[y][x] == '*'){
				MUL.push_back(make_pair(y, x));
			}
		}
	}
	for(int i = 0; i < MUL.size(); i++){
		for(int j = 0; j < 4; j++){
			int nextY = MUL[i].first + dy[j], nextX = MUL[i].second + dx[j];
			//다음에 물이 찰 곳이 맵 안이어야 하고, 비버의 구멍이 아니어아야하고,
			//돌이 아니어야 한다.
			if(isIn(nextY, nextX) && map[nextY][nextX] != 'D' && map[nextY][nextX] != 'X'){
				map[nextY][nextX] = '*';
			}
		}
	}

	//first는 목적지와의 길이, second.fisrt는 y, second.second는 x
	vector<pair<int, pair<int, int> > > nextGil;
	//고슴도치가 이동함.
	for(int i = 0; i < 4; i++){
		int nextY = nowSy + dy[i], nextX = nowSx + dx[i];
		int dist = abs(d_y - nextY) + abs(d_x - nextX);
		nextGil.push_back(make_pair(dist,make_pair(nextY, nextX)));
	}

	sort(nextGil.begin(), nextGil.end());

	for(int i = 0; i < 4; i++){
		int nextY = nextGil[i].second.first, nextX = nextGil[i].second.second;
		//고슴도치가 이동할 곳은, 안쪽이고, 돌이 아니고, 물이 아닌 곳으로 이동.
		if(isIn(nextY, nextX) && map[nextY][nextX] != 'X' && map[nextY][nextX] != '*'){
			moving(map, nextY, nextX, nowMove + 1,path);
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	vector<string> map;
	cin>>r>>c;
	for(int i = 0; i < r; i++){
		string temp;
		cin>>temp;
		map.push_back(temp);
		for(int j = 0; j < temp.size(); j++){
			if(temp[j] == 'S'){
				s_y = i; s_x = j;
			}
			else if(temp[j] == 'D'){
				d_y = i; d_x = j;
			}
		}
	}
	vector<pair<int, int> > path;
	moving(map, s_y, s_x, 0, path);
	if(minMove <= 2500)
		cout<<minMove<<endl;
	else
		cout<<"KAKTUS"<<endl;





	return 0;
}