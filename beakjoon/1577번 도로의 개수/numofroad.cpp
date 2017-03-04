#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class p{
public:
	int from_y, from_x, to_y, to_x;
};

int N, M, K;
p broken[101];
long long cache[101][101];
long long gototheNM(int y, int x);
int main(){
	freopen("input.txt","r",stdin);
	cin>>N>>M>>K;
	int yy[2], xx[2];
	for(long long i = 0 ; i < K; i++){
		cin>>yy[0]>>xx[0]>>yy[1]>>xx[1];
		sort(yy, yy + 2 ); sort(xx, xx + 2);
		// cout<<yy[0]<<" "<<yy[1]<<endl;
		broken[i].from_y = yy[0];
		broken[i].from_x = xx[0];
		broken[i].to_y = yy[1];
		broken[i].to_x = xx[1];
	}

	// cout<<broken[1].from_y<<endl;
	memset(cache, -1, sizeof(cache));

	cout<<gototheNM(0,0)<<endl;


	// for(int i = 0; i < N; i++){
	// 	for(int j = 0 ; j < M; j++){
	// 		cout<<cache[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	return 0;
}

long long gototheNM(int y, int x){
	if( y == N  && x == M ) return 1;

	if( y > N || x > M) return 0;

	long long& ret = cache[y][x];

	if(ret != -1) return ret;

	ret = 0;
	
	bool check = false;
	
	for(int i = 0; i < K; i++){
		if(y == broken[i].from_y && x == broken[i].from_x
			&& y + 1 == broken[i].to_y && x == broken[i].to_x ){
			check = true;
			break;
		}
	}

	if(!check)
		ret += gototheNM(y+1, x);

	check = false;
	
	for(int i = 0; i < K; i++){
		if(y == broken[i].from_y && x == broken[i].from_x
			&& y == broken[i].to_y && x + 1 == broken[i].to_x ){
			check = true;
			break;
		}
	}
	
	if(!check)
		ret += gototheNM(y, x + 1);

	return ret;
}