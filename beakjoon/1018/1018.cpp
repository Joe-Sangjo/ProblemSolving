#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
int m, n;
//입력되는 보드판
vector<string> board;
//비교할 보드판 8*8
vector<string> cmp1, cmp2;
string ans[2] = {"WBWBWBWB", "BWBWBWBW"};

int main(){
	freopen("input.txt","r",stdin);

	cin>>m>>n;

	for(int i = 0; i < m; i++){
		string inp; cin>>inp;
		board.push_back(inp);
		// cout<<board[i]<<endl;
	}
	//비교할 보드판 2개를 만든다.
	for(int i = 0; i < 8; i++){
		cmp1.push_back(ans[i % 2]);
		cmp2.push_back(ans[(i + 1) % 2]);
	}

	int ret = 0x3f3f3f3f;
	//보드판을 돌면서
	for(int i = 0; i <= m - 8; i++){
		for(int j = 0; j <= n - 8; j++){
			//기준이 되는 보드판 2개와 차이를 비교한다

			int diff1 = 0, diff2 = 0;
			for(int ii = 0; ii < 8; ii++){
				for(int jj = 0; jj < 8; jj++){
					int nowI = i+ii, nowJ = j + jj;
					//첫번째 기준 보드판과의 차이를 저장
					if(board[nowI][nowJ] != cmp1[ii][jj])
						diff1++;

					//두번째 기준 보드판과의 차이를 저장
					if(board[nowI][nowJ] != cmp2[ii][jj]){
						diff2++;
					}
				}
			}
			//가장 작은 값을 저장한다.
			ret = min(ret, min(diff1, diff2));
		}
	}

	cout<<ret<<endl;
	return 0;
}