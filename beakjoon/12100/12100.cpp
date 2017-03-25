#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int maxNum = -1;

void printBoard(vector<vector<int> > nowBoard){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<nowBoard[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}




//nowBoard는 지금의 board, dir는 방향
//dir 이 0 -> 왼쪽, 1-> 오른쪽, 2-> 위쪽, 3-> 아래쪽
//num은 이동 횟수 최대 5번.
void moving(vector<vector<int> > nowBoard, int dir, int num){
	//기저사례
	if(num > 5) return;


	// cout<<"////////////////////"<<endl;
	// printBoard(nowBoard);
	//왼쪽
	if(dir == 0){
		for(int row = 0; row < n; row++){
			//0을 제거해서 땅겨주는 역할
			vector<int> notZero;
			for(int column = 0; column < n; column++){
				if(nowBoard[row][column] != 0){
					notZero.push_back(nowBoard[row][column]);
				}
			}

			for(int column = 0; column < notZero.size(); column++){
				nowBoard[row][column] = notZero[column];
			}
			for(int column = notZero.size(); column < n; column++){
				nowBoard[row][column] = 0;
			}

			//숫자 합치기
			for(int column = 0; column < n - 1; column++){
				//다음 열과 같아버리면, 그 2개를 합치고, 나머지를 땡겨서 0으로 만든다.
				if(nowBoard[row][column] == nowBoard[row][column + 1]){
					nowBoard[row][column] *= 2;
					//나머지는 땅긴다.
					for(int nextColumn = column + 1; nextColumn < n - 1; nextColumn++){
						nowBoard[row][nextColumn] = nowBoard[row][nextColumn + 1];
					}
					nowBoard[row][n - 1] = 0;
				}
			}
		}
		

	}
	//오른쪽
	else if(dir == 1){
		for(int row = 0; row < n; row++){

			//0을 제거해서 땅겨주는 역할
			vector<int> notZero;
			for(int column = n - 1; column >= 0; column--){
				if(nowBoard[row][column] != 0){
					notZero.push_back(nowBoard[row][column]);
				}
			}

			for(int i = 0; i < notZero.size(); i++){
				nowBoard[row][n - 1 - i] = notZero[i];
			}

			for(int column = n - notZero.size() - 1; column >= 0; column--){
				nowBoard[row][column] = 0;
			}



			for(int column = n - 1; column > 0; column--){
				//다음 열과 같아버리면, 그 2개를 합치고, 나머지를 땡겨서 0으로 만든다.
				if(nowBoard[row][column] == nowBoard[row][column - 1]){
					nowBoard[row][column] *= 2;
					//나머지는 땅긴다.
				
					for(int nextColumn = column - 1; nextColumn > 0; nextColumn--){
						nowBoard[row][nextColumn] = nowBoard[row][nextColumn - 1];
					}
					nowBoard[row][0] = 0;
				}
			}
		}
	}
	//위쪽
	else if(dir == 2){
		for(int column = 0; column < n; column ++){



			//0을 제거해서 땅겨주는 역할
			vector<int> notZero;
			for(int row = 0; row < n; row++){
				if(nowBoard[row][column] != 0){
					notZero.push_back(nowBoard[row][column]);
				}
			}

			for(int row = 0; row < notZero.size(); row++){
				nowBoard[row][column] = notZero[row];
			}
			for(int row = notZero.size(); row < n; row++){
				nowBoard[row][column] = 0;
			}
		


			for(int row = 0; row < n - 1; row++){
				if(nowBoard[row][column] == nowBoard[row + 1][column]){
					nowBoard[row][column] *= 2;
					for(int nextRow = row + 1; nextRow < n - 1; nextRow++){
						nowBoard[nextRow][column] = nowBoard[nextRow + 1][column];
					}
					nowBoard[n - 1][column] = 0;
				}
			}
		}

	}
	//아래쪽
	else{
		for(int column = 0; column < n; column ++){

			//0을 제거해서 땅겨주는 역할
			vector<int> notZero;
			for(int row = n - 1; row >= 0; row--){
				if(nowBoard[row][column] != 0){
					notZero.push_back(nowBoard[row][column]);
				}
			}

			for(int i = 0; i < notZero.size(); i++){
				nowBoard[n - 1 - i][column] = notZero[i];
			}

			for(int row = n - notZero.size() - 1; row >= 0; row--){
				nowBoard[row][column] = 0;
			}




			for(int row = n - 1; row > 0; row--){
				if(nowBoard[row][column] == nowBoard[row - 1][column]){
					nowBoard[row][column] *= 2;
					for(int nextRow = row - 1; nextRow > 0; nextRow--){
						nowBoard[nextRow][column] = nowBoard[nextRow - 1][column];
					}
					nowBoard[0][column] = 0;
				}
			}
		}

	}

	// printBoard(nowBoard);
	// cout<<"////////////////////"<<endl;
	//값을 비교
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			maxNum = max(maxNum, nowBoard[i][j]);
		}
	}

	//자식을 만든다.
	for(int i = 0; i < 4; i++){
		moving(nowBoard, i, num + 1);
	}

}

int main(){

	freopen("input.txt","r",stdin);
	vector<vector<int> > board;

	cin>>n;
	board = vector<vector<int> >(n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int temp; cin>>temp;
			board[i].push_back(temp);
		}
	}
	// printBoard(board);
	for(int i = 0; i < 4; i++){
		moving(board, i, 1);
	}
	cout<<maxNum<<endl;


	return 0;
}