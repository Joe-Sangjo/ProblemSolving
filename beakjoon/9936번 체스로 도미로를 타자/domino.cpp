#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int NEGINF = -987654321;
int N, K;
int array[1001][3];
int dp[1000][1000][3];
int domino(int k_num,int y, int x);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	cin>>N>>K;

	for(int y = 0; y < N; y++){
		cin>>array[y][0]>>array[y][1]>>array[y][2];
		// cout<<array[y][0]<<" "<<array[y][1]<<" "<<array[y][2]<<endl;
	}
	// cout<<K<<endl;
	
	for(int k_num = 0; k_num < K; k_num++){
		for(int y = 0; y < N; y++){
			for(int x = 0; x < 3; x++){
				dp[k_num][y][x] = NEGINF;
			}
		}
	}
	vector<int, int> dft;
	cout<<domino(0,0,0)<<endl;


	// cout<<endl<<endl;
	// for(int k_num = 0; k_num < K; k_num++){
	// 	for(int y = 0; y < N; y++){
	// 		for(int x = 0; x < 3; x++){
	// 			cout<<dp[k_num][y][x]<<" ";
	// 		}
	// 		cout<<endl;
	// 	}
	// 	cout<<endl<<endl;
	// }
	return 0;
}

int domino(int k_num,int y, int x){
	// cout<<k_num <<"  "<<y<<"  "<<x<<endl; 
	if(k_num == K) return 0;

	if(y >= N || x >= 3)	return 0;

	int& ret = dp[k_num][y][x];

	if(ret != NEGINF) return ret;

	ret = NEGINF+1;
	int cand = 0;
	ret = max(ret, domino( k_num, y+1, x));
	ret = max(ret, domino( k_num,y, x + 1));
	if(x < 2){
		// cand = domino( k_num + 1,y + 1, x) + domino( k_num + 1, y, x + 2) + array[y][x] + array[y][x + 1];
		cand = max(domino(k_num + 1, y +1 ,x), domino(k_num + 1, y, x+ 2)) + array[y][x] + array[y][x+1];
	}


	ret = max(ret, cand);

	if(y < N - 1){
		// cand = domino( k_num + 1,y + 2, x) + domino( k_num + 1,y, x + 1) + array[y][x] + array[y + 1][x];
		cand = max(domino(k_num + 1, y + 2, x), domino(k_num + 1, y, x + 1) )+ array[y][x] +array[y+1][x];
	}
	
	ret = max(ret, cand);

	return ret;

}