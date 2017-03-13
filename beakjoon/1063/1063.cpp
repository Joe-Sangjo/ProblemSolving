#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string moveIndex[8] = {"R", "L", "B", "T","RT", "LT","RB","LB"};

int dy[8] = {0,  0, -1, 1, 1, 1 , -1, -1 };
int dx[8] = {1, -1, 0,  0, 1, -1, 1 , -1};

string king, dol;
int n;
int queue[51];

//out했으면 true, in이면 false
bool isOut(int y, int x){
	return y >= 8 || y < 0 || x >= 8 || x < 0;
}
int main(){
	freopen("input.txt","r",stdin);
	cin>>king>>dol>>n;

	for(int i = 0; i < n; i++){
		string temp;
		cin>>temp;
		for(int j = 0; j < 8; j++){
			if(temp == moveIndex[j]){
				queue[i] = j;
				break;
			}
		}
	}
	// cout<<king<<endl;
	int kingX = king[0] - 'A';
	int kingY = king[1] - '1';
	int dolX = dol[0] - 'A';
	int dolY = dol[1] - '1';
	// cout<<kingY<<" "<<kingX<<endl;
	for(int i = 0; i < n ; i ++){

		int nextKingY = kingY + dy[queue[i]];
		int nextKingX = kingX + dx[queue[i]];
		//킹이 다음에 이동할 곳이 돌이 있는 곳이라면
		int nextDolY = dolY, nextDolX = dolX;
		if(nextKingY == dolY && nextKingX == dolX){
			nextDolY += dy[queue[i]], nextDolX += dy[queue[i]];
		}
		//둘 중 하나라도 범위 밖으로 넘어가면 띵가 넘어간다.
		if(!(isOut(nextDolY, nextDolX) || isOut(nextKingY, nextKingX))){
			//안넘어 가면
			kingY = nextKingY, kingX = nextKingX;
			dolY = nextDolY, dolX = nextDolX;			
		}
	}
	char a = 'A', b = '1';
	cout<<char((int)a + kingX)<<char((int)b + kingY)<<endl;
	cout<<char((int)a + dolX)<<char((int)b + dolY);


	return 0;
}