#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int n;
int board[501][501];
int cache[501][501];
int dy[4] = { -1, 0, 1,  0};
int dx[4] = {  0, 1, 0, -1};
int alive(int y, int x);
int main(){

	freopen("input.txt","r",stdin);
	memset(cache, -1, sizeof(cache));
	// cin>>n;
	n = 4;

	for(int i = 0 ; i < n; i++){
		for(int j = 0; j< n; j++){
			// cout<<1<<endl;
			cin>>board[i][j];
		}
	}

	int maxdays = 0;

	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			maxdays = max(maxdays, alive(i,j));
		}
	}
	cout<<maxdays<<endl;


	return 0;
}


int alive(int y, int x){

	if(y < 0 || y >= n || x < 0 || x >= n) return 0;

	int& ret = cache[y][x];

	if(ret != -1) return ret;
	ret = 1;

	for(int i = 0; i < 4; i++){
		if(board[y][x] < board[y + dy[i]][x + dx[i]])
			ret = max(ret, alive(y + dy[i], x + dx[i]) + 1);
	}
	return ret;
}