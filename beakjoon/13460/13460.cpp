#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<string> map;

int minNum = 100;
int oy, ox;

//      0 -> x감소, 1 -> x증가 , 2 -> y감소, 3-> y증가
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0 };

void printMap(){
	for(int i = 0; i < map.size(); i++){
		cout<<map[i]<<endl;
	}
	cout<<endl;
}
//num은 움직인 횟수 -> 10번이상 넘어갈 필요가 없음
//m은 지금 상태의 맵
//dir은 0일 때 왼쪽, 1일때 오른쪽, 2일 때 위, 3일 때 아래
//      0 -> x감소, 1 -> x증가 , 2 -> y감소, 3-> y증가
void search(int num, int ry, int rx, int by, int bx, int dir){
	// cout<<num<<" "<<dir<<endl;
	if(num >= minNum || num > 10){
		return;
	}

	//지금 상태 맵을 dir에 따라 상태이동 ** 아주 중요
	int nowry = ry, nowrx = rx, nowby = by, nowbx = bx;
	map[ry][rx] = 'R';
	map[by][bx] = 'B';

	bool checkR = false;
	bool checkB = false;
	

	
	while(1){

		int nextRy = nowry + dy[dir];
		int nextRx = nowrx + dx[dir];
		int nextBy = nowby + dy[dir];
		int nextBx = nowbx + dx[dir];
		//R이 구멍에 빠진 경우에는 R을 벽에 있다고 생각
		if(checkR){
			nextRy = 0, nextRx = 0;
			//R이 구멍에 따지고 Blue가 움직일 곳이 벽이면 그만둔다.
			if(map[nextBy][nextBx] == '#'){
				break;
			}
		}


		//둘다 벽일 경우 -> 그만 둔다.
		if(map[nextRy][nextRx] == '#' && map[nextBy][nextBx] == '#'){
			break;
		}
		//Red만 벽인 경우 블루를 움직인다.
		else if(map[nextRy][nextRx] == '#'){
			//Red는 안움직이므로, 블루가 움직일 공간에 지금의 Red가 있으면 안된다.
			if(!(nextBy == nowry && nextBx == nowrx)){
				map[nowby][nowbx] = '.';
				nowby = nextBy; nowbx = nextBx;
				map[nowby][nowbx] = 'B';
			}
			//둘다 안움직이는 경우이므로 끝낸다
			else{
				break;
			}
		}
		//Blue만 벽인 경우 Red를 움직인다.
		else if(map[nextBy][nextBx] == '#'){
			//Blue는 안움직이므로, Red가 움직일 공간에 지금의 Blue가 있으면 안된다.
			if(!(nextRy == nowby && nextRx == nowbx)){
				map[nowry][nowrx] = '.';
				nowry = nextRy; nowrx = nextRx;
				map[nowry][nowrx] = 'R';
			}
			//둘다 안움직이는 경우이므로 끝낸다
			else{
				break;
			}
		}
		//둘다 움직인다.
		else{
			map[nowry][nowrx] = '.';
			map[nowby][nowbx] = '.';
			nowby = nextBy; nowbx = nextBx;
			nowry = nextRy; nowrx = nextRx;
			map[nowby][nowbx] = 'B';
			map[nowry][nowrx] = 'R';
		}

		//움직임으로 인해 구멍에 빠지는 경우를 살펴봐야함.
		//Red가 빠지는 경우
		if(nowry == oy && nowrx == ox){
			checkR = true;
			map[nowry][nowrx] = 'O';
			nowry = 0, nowrx = 0;
		}
		//Blue가 빠지는 경우 -> 그만 둔다 Blue가 빠지면 무조건 안됨.
		if(nowby == oy && nowbx == ox){
			checkB = true;
			map[oy][ox] = 'O';
			break;
		}
	}

	//Blue가 빠지는 경우 무조건 안됨.
	if(checkB){
		return;
	}
	//Red가 빠지는 경우 게임 끝! 기록
	if(checkR){
		minNum = min(minNum, num);
		return;
	}

	//더이상 변화가 없을 때 그만 둔다.
	if(ry == nowry && rx == nowrx && by == nowby && bx == nowbx){
		return;
	}

	//다음번으로 탐색
	for(int i = 0; i < 4; i++){
		search(num + 1, nowry, nowrx, nowby, nowbx, i);
	}

}
int main(){

	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int ry, rx, by, bx;

	for(int i = 0; i < n; i++){
		string temp;
		cin>>temp;
		map.push_back(temp);
		for(int j = 0; j < map[i].size(); j++){
			if(map[i][j] == 'R'){
				ry = i, rx = j;
			}
			else if(map[i][j] == 'B'){
				by = i, bx = j;
			}
			else if(map[i][j] == 'O'){
				oy = i, ox = j;
			}
		}
	}
	// printMap();
	// cout<<endl<<endl<<endl;



	for(int i = 0; i < 4; i++){
		search(1, ry, rx, by, bx, i);		
	}

	if(minNum > 20){
		cout<<-1<<endl;
	}
	else{
		cout<<minNum<<endl;
	}

	return 0;
}