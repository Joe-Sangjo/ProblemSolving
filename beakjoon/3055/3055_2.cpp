#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define mp make_pair
using namespace std;
int r, c;
//S는 고슴도치, D는 비버의 굴
int Sy, Sx, Dy, Dx;

vector<string> map;

int Sdist[51][51], Wdist[51][51];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
bool isIn(int y, int x){
	return y >= 0 && y < r && x >= 0 && x < c;	
}
int main(){
	cin>>r>>c;
	map = vector<string>(r);

	//fist가 0이면 고슴도치, 1이면 물
	queue<pair<int, pair<int, int> > > q;
	memset(Sdist, -1, sizeof(Sdist));
	memset(Wdist, -1, sizeof(Wdist));

	for(int i = 0; i < r; i++){
		cin>>map[i];
		for(int j = 0; j < map[i].size(); j++){
			switch(map[i][j]){
				case 'S':
					Sy = i; Sx = j;
				break;
				case 'D':
					Dy = i; Dx = j;
				break;
				case '*':
					//first == 1, 물
					q.push(mp(1, mp(i,j)));	
					Wdist[i][j] = 0;
				break;
			}
		}
	}

	Sdist[Sy][Sx] = 0;
	q.push(mp(0, mp(Sy,Sx)));

	while(!q.empty()){

		int what = q.front().first;
		int hereY = q.front().second.first;
		int hereX = q.front().second.second;

		q.pop();

		//끝남 목적지에 도착
		if(what == 0 && hereY == Dy && hereX == Dx) break;

		//고슴도치
		if(what == 0){
			int hereDist = Sdist[hereY][hereX];
			for(int i = 0; i < 4; i++){
				int nextY = hereY + dy[i], nextX = hereX + dx[i];
				//안이고, 돌이 없어야 하고, 고슴도치가 방문하지 않았어야하고
				//물이 있으면 안된다.
				if(isIn(nextY, nextX) && map[nextY][nextX] != 'X'
				 && Sdist[nextY][nextX] == -1 && Wdist[nextY][nextX] == -1){
					Sdist[nextY][nextX] = hereDist + 1;
					q.push(mp(0, mp(nextY, nextX)));
				}
			}
		}
		//물
		else{
			int hereDist = Wdist[hereY][hereX];
			for(int i = 0; i < 4; i++){
				int nextY = hereY + dy[i], nextX = hereX + dx[i];
				
				if(isIn(nextY, nextX) && map[nextY][nextX] != 'X' 
					&& Wdist[nextY][nextX] == -1 && !(nextY == Dy && nextX == Dx) ){
					Wdist[nextY][nextX] = hereDist + 1;
					q.push(mp(1, mp(nextY, nextX)));
				}
			}
		}
	}

	if(Sdist[Dy][Dx] == -1){
		cout<<"KAKTUS"<<endl;
	}
	else{
		cout<<Sdist[Dy][Dx]<<endl;
	}
	return 0;
}