#include <iostream>
#include <cstdio>
#include <cstring>

#define MOD 10000000
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool board[300][300];
bool takenx[300];
bool takeny[300];

int n;
int cnt;
void print();
void makepoly(int N,int y, int x);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;
	for(int test_case = 0 ; test_case < TC-1; test_case++){
		cin>>n;
		memset(board, 0, sizeof(board));
		// cout<<makepoly(n,150,150)<<endl<<endl<<endl;
	}
	cnt = 0;
	n = 3;
	board[150][150] = 1;
	makepoly(n, 150,150);
	board[150][150] = 0;
	cout<<cnt<<endl;






	return 0;
}

void makepoly(int N, int y, int x){
	if(N == 1){
		print();
		cnt++;
		return;
	} 


	for(int i = 0; i < 4; i++){
		if(!board[y + dy[i]][x + dx[i]]){
			board[y + dy[i]][x + dx[i]] = 1;
			makepoly(N-1, y+dy[i], x+dx[i]);
			board[y + dy[i]][x + dx[i]] = 0;
		}
	}
	if(N > 2){
		for(int i = 0 ; i < 3; i++){
			for(int j = i+1 ; j < 4 ; i++){
				if(!board[y + dy[i]][x + dx[i]] && !board[y + dy[j]][x + dx[j]]){
					board[y + dy[i]][x + dx[i]] = 1;
					board[y + dy[j]][x + dx[j]] = 1;
					makepoly(N-2, y+dy[i], x+dx[i]);
					makepoly(N-2, y+dy[j], x+dx[j]);
					board[y + dy[j]][x + dx[j]] = 0;
					board[y + dy[i]][x + dx[i]] = 0;
				
				}
			}
		}
	}
	if(N>3){
		for(int i = 0 ; i < 2; i++){
			for(int j = i+1; j < 3; j++){
				for(int k = j +1 ; k < 4; k ++){
					if(!board[y + dy[i]][x + dx[i]] && !board[y + dy[j]][x + dx[j]] 
						&& !board[y + dy[k]][x + dx[k]]){
						board[y + dy[i]][x + dx[i]] = 1;
						board[y + dy[j]][x + dx[j]] = 1;
						board[y + dy[k]][x + dx[k]] = 1;
						makepoly(N-3, y+dy[i], x+dx[i]);
						makepoly(N-3, y+dy[j], x+dx[j]);
						makepoly(N-3, y+dy[k], x+dx[k]);
						board[y + dy[k]][x + dx[k]] = 0;
						board[y + dy[i]][x + dx[i]] = 0;
						board[y + dy[j]][x + dx[j]] = 0;

					}
				}
			}
		}
	}

	if(N>4 &&!board[y + dy[0]][x + dx[0]] && !board[y + dy[1]][x + dx[1]] 
					&& !board[y + dy[3]][x + dx[3]] && !board[y + dy[2]][x + dx[2]]){

					board[y + dy[0]][x + dx[0]] = 1;
					board[y + dy[1]][x + dx[1]] = 1;
					board[y + dy[2]][x + dx[2]] = 1;
					board[y + dy[3]][x + dx[3]] = 1;
					makepoly(N-4, y+dy[0], x+dx[0]);
					makepoly(N-4, y+dy[1], x+dx[1]);
					makepoly(N-4, y+dy[2], x+dx[2]);
					makepoly(N-4, y+dy[3], x+dx[3]);
					board[y + dy[0]][x + dx[0]] = 0;
					board[y + dy[1]][x + dx[1]] = 0;
					board[y + dy[2]][x + dx[2]] = 0;
					board[y + dy[3]][x + dx[3]] = 0;
	}

}

void print(){
	for(int i = 150-n ; i <= 150+n ; i ++){
		for(int j = 150-n ; j <= 150+n ; j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}