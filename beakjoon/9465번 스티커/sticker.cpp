#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int score[2][100001];

int n;
int cache[2][100001];
int detach(int y, int x);
int main(){

	freopen("input.txt","r",stdin);

	int TC; cin>>TC;
	int maxscore;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n;
		memset(cache, -1, sizeof(cache));
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n ; j++){
				cin>>score[i][j];
				// cout<<score[i][j]<<" ";
			}
			// cout<<endl;
		}
		maxscore = 0;
		// for(int i = 0 ; i <2 ;i++){
		// 	for(int j = 0 ; j < n ;j++){
		// 		maxscore = max(maxscore, detach(i,j));
		// 	}
		// }
		maxscore = max(maxscore, detach(0,0));
		maxscore = max(maxscore, detach(0,1));
		maxscore = max(maxscore, detach(1,0));
		maxscore = max(maxscore, detach(1,1));

		cout<<maxscore<<endl;
	}

	return 0;
}
int detach(int y, int x){
	if(x == n-1) return score[y][x];

	if(x >= n) return 0;
	int& ret = cache[y][x];

	if(ret != -1) return ret;

	ret = 0;
	if(y == 0 ){
		if(x + 1 < n)
			ret = max(ret, detach(1, x + 1) + score[y][x]);
		if(x + 2 < n)
			ret = max(ret, detach(1, x + 2) + score[y][x]);
	}
	else{
		if(x + 1 < n)
			ret = max(ret, detach(0, x + 1) + score[y][x]);
		if(x + 2 < n)
			ret = max(ret, detach(0, x + 2) + score[y][x]);

	}
	// if(x + 2 < n)
	// 	ret = max(ret, detach(y, x + 2) + score[y][x]);
	// if(x + 3 < n)
	// 	ret = max(ret, detach(y, x + 3) + score[y][x]);

	return ret;
}