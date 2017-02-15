#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int MOD = 10007;

int how_many[30];
int N;
int matrix[30][102][102];
int p;
int answer_matrix[102][102];
int multi(int po);
void solve(int po);
void print_matrix(int aaa[102][102]);
int main(){
	freopen("input.txt","r",stdin);

	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>N>>p;
		memset(matrix, 0, sizeof(matrix));
		memset(how_many, 0, sizeof(how_many));
		memset(answer_matrix, 0, sizeof(answer_matrix));
		for(int i = 1 ; i <= N ; i++){
			for(int j = 1; j <= N ; j++){
				cin>>matrix[0][i][j];
			}
		}


		int aaa = multi(1);
		how_many[0] = aaa;
		int first;
		for(int i = 0 ; i < 30; i++){
			if(how_many[i]){
				first = i;
				break;
			}
		}

		for(int i = 1 ; i <= N; i++){
			for(int j = 1 ; j <= N; j++){
				answer_matrix[i][j] = matrix[first][i][j];
			}
		}

		solve(first + 1);

		print_matrix(answer_matrix);

	}
	return 0;
}

int multi(int po){
	if(pow(2,po) > p) return -1;
	for(int i = 1 ; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++){
				matrix[po][i][j] += (matrix[po-1][i][k]*matrix[po-1][k][j]);
			}
			matrix[po][i][j] %= MOD;
		}
	}
	
	int aaa = multi(po + 1);
	
	if(aaa == -1){
		how_many[po] = p / pow(2, po);
		return (p % (int)pow(2,po));
	}
	else{
		how_many[po] = aaa / pow(2,po);
		return (aaa % (int)pow(2, po));
	}

}

void solve(int po){
	if(pow(2,po) > p) return;
	

	if(how_many[po]){
		int prev_matrix[102][102];
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				prev_matrix[i][j] = answer_matrix[i][j];
			}
		}
		int a;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				a = 0;
				for(int k = 1; k <= N; k++){
					a += (prev_matrix[i][k] * matrix[po][k][j]);
				}
				answer_matrix[i][j] = a %  MOD;
			}
		}
	}
	solve(po + 1);

}

void print_matrix(int aaa[102][102]){
	for(int i = 1; i <= N ; i++){
		for(int j = 1; j <= N; j++){
			cout<<aaa[i][j]<<" ";
		}
		cout<<endl;
	}
}