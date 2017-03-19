#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//a : 가로 b : 세로 n:로봇수 m:명령수
int a, b, n ,m;

// L -> 시계 반대 방향
// R -> 시계 방향
// 북N 서W 남S 동E
// L: 인덱스가 증가, R 인덱스가 감소
int dy[4] = {1 , 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
char dir[4] = { 'N', 'W', 'S', 'E'};
int robotX[101];
int robotY[101];
//로봇 방향 N E W S
int robotDirection[101];

//out되면 true
bool isOut(int index){
	return robotY[index] > b || robotX[index] > a || robotY[index] <= 0 || robotX[index] <= 0;
}

//회전 명령 L은 시계 반대방향 R은 시계방향
//L :  N -> W -> S -> E -> N
//R :  N -> E -> S -> W -> N
void Rotation(int index, char order, int num){
	//왼쪽 : 숫자가 커진다.
	if(order == 'L'){
		robotDirection[index] += num;
		robotDirection[index] %= 4; 
	}
	//오른쪽 : 숫자가 작아진다.
	else if(order == 'R'){
		robotDirection[index] -= num;
		robotDirection[index] += 10000;
		robotDirection[index] %= 4;
	}
}

//index번 로봇이 앞으로 한칸 가라
void MoveMove(int index){
	int movingIndex = robotDirection[index];
	robotX[index] += dx[movingIndex];
	robotY[index] += dy[movingIndex];
}

//-1을 리턴하면 충돌하지 않고, 
//리턴 하는 번호의 +1번 로봇과 충돌함
int Crash(int index){
	for(int i = 0; i < n; i++){
		if(i != index && robotX[index] == robotX[i] && robotY[index] == robotY[i]){
			return i;
		}
	}
	return -1;
}

int main(){

	cin>>a>>b>>n>>m;

	for(int i = 0; i < n ; i++){
		cin>>robotX[i]>>robotY[i];
		char in; cin>>in;
		for(int j = 0; j < 4; j++){
			if(in == dir[j]){
				//N : 0 , W : 1 , S : 2 , E : 3
				robotDirection[i] = j;
				break;
			}			
		}
	}	

	for(int i = 0; i < m; i++){
		int nowRobot, movingNum; char order;
		cin>>nowRobot>>order>>movingNum;
		//movingNum번 앞으로 이동해라
		nowRobot--;
		// cout<<nowRobot<<endl;
		if(order == 'F'){
			for(int j = 0; j < movingNum; j++){
				//이동하고
				MoveMove(nowRobot);				
				//밖으로 나갔는지 확인
				if(isOut(nowRobot)){
					cout<<"Robot"<<" "<<nowRobot + 1<<" crashes into the wall"<<endl;
					return 0;
				}
				//다른 로봇과 충돌했는지 확인
				int c = Crash(nowRobot);
				if(c != -1){
					cout<<"Robot"<<" "<<nowRobot + 1<<" crashes into robot "<<c + 1<<endl;
					return 0;
				}
				// cout<<robotX[nowRobot]<<" "<<robotY[nowRobot]<<endl; 

			}
		}
		//movingNum번 회전해라.
		else{
			Rotation(nowRobot, order, movingNum);
		}
	}
	cout<<"OK"<<endl;


	return 0;
}