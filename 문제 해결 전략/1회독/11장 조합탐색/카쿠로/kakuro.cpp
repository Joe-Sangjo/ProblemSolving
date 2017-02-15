#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int N, Q;
bool isWhite[22][22];
int board[22][22];
int sum[21][21][2];
void KAKURO(int y, int x);
void print();
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;
	cin>>TC;

	for(int test_case = 0;  test_case < TC; test_case++){
		cin>>N;
		for(int i = 1; i <= N ; i++){
			for(int j = 1 ; j <= N; j++){
				cin>>isWhite[i][j];
				// cout<<isWhite[i][j]<<" ";
			}
			// cout<<endl;
		}
		memset(board, -1, sizeof(board));
		memset(sum, -1, sizeof(sum));
		cin>>Q;
		int buf1, buf2, buf3, buf4;
		for(int i = 0; i < Q; i++){
			cin>>buf1>>buf2>>buf3>>buf4;
			sum[buf1][buf2][buf3] = buf4;
		}
		KAKURO(2,2);
		print();
	}
	return 0;
}
void KAKURO(int y, int x){
	// cout<<y<<" "<<x<<endl;
	if(!isWhite[y][x]){
		KAKURO(y,x + 1);
	}
	
	if(x > N){
		KAKURO(y + 1, 1);
	}

	if(y > N){

		return;
	}

	// cout<<y<<" "<<x<<endl;
	
	for(int num = 1; num <= 9; num++){

		
		board[y][x] = num;
		// print();
		if(!isWhite[y][x + 1]){
			int total = 0, i = 0;
			while(isWhite[y][x - i]){
				total += board[y][x - i];
				i++; 
			}
			if(sum[y][x - i][0] != total)	continue;
		}

		if(!isWhite[y + 1][x]){
			int total = 0, i = 0;
			while(isWhite[y - i][x]){
				total += board[y - i][x];
				i++;
			}
			if(sum[y - i][x][1] != total)	continue;
		}

		if(board[y][x-1] == num || board[y-1][x] == num)	continue;
		
		
		// cout<<y<<"    "<<x<<"     "<<num<<endl;
		KAKURO(y, x + 1);
	
	}
	board[y][x] = -1;
	return;

}
void print(){
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			cout<<board[y][x]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}