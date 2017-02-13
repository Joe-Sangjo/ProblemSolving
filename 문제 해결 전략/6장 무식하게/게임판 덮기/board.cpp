#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char board[22][22];
int H, W;
int caseNum;
int dotCnt;
int recur = 0;
void paint(int i,int j);
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	cin>>T;
	for(int test_case=0; test_case<T;test_case++){
   		cin>>H>>W;
   		dotCnt = 0;
   		caseNum = 0;
   		memset(board,'#',22*22*sizeof(char));
   		for(int i = 1 ; i <= H ; i++){
   			for(int j = 1 ; j <= W ; j++){
   				cin>>board[i][j];
   				if(board[i][j]=='.')
   					dotCnt++;
   			}
   		}
   		if(dotCnt % 3 != 0 ){
   			cout<<"0"<<endl;
   		}
   		else{
   			paint(1,1);
   			cout<<caseNum<<endl;
   		}

	}
	cout<<recur<<endl;
	return 0;
}
void paint(int i,int j){
	recur++;
	if(i == H && j == W){
		if(dotCnt == 0)
			caseNum++;
		return;
	}
	else if(board[i][j] == '#'){
		if(j<W){
			paint(i,j+1);
		}
		else{
			paint(i+1,1);
		}
	}
	else{

		if(board[i][j+1] == '.' && board[i+1][j+1] == '.'){
			
			dotCnt -= 3;
			board[i][j] = '#'; board[i][j+1] = '#'; board[i+1][j+1] = '#';
			if(j>=W-1){
				paint(i+1,1);
			}
			else{
				paint(i,j+1);
			}
			board[i][j] = '.'; board[i][j+1] = '.'; board[i+1][j+1] = '.';
			dotCnt += 3;
		}
		if(board[i+1][j] == '.' && board[i+1][j-1] == '.'){
			dotCnt -= 3;
			board[i][j] = '#'; board[i+1][j] = '#'; board[i+1][j-1] = '#';
			if(j<=W){
				paint(i,j+1);
			}
			else{
				paint(i+1,1);
			}
			board[i][j] = '.'; board[i+1][j] = '.'; board[i+1][j-1] = '.';
			dotCnt += 3;
		}
		if(board[i+1][j] == '.' && board[i+1][j+1] == '.'){
			dotCnt -= 3;
			board[i][j] = '#'; board[i+1][j] = '#'; board[i+1][j+1] = '#';
			if(j<W){
				paint(i,j+1);
			}
			else{
				paint(i+1,1);
			}
			board[i][j] = '.'; board[i+1][j] = '.'; board[i+1][j+1] = '.';
			dotCnt += 3;
		}
		if(board[i][j+1] == '.' && board[i+1][j] == '.'){
			dotCnt -= 3;
			board[i][j] = '#'; board[i][j+1] = '#'; board[i+1][j] = '#';
			if(j<W-1){
				paint(i,j+1);
			}
			else{
				paint(i+1,1);
			}
			board[i][j] = '.'; board[i][j+1] = '.'; board[i+1][j] = '.';
			dotCnt += 3;
		}
	}
}