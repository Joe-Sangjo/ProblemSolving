#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 999999999;
int N;
bool array[21][21];
int cache[41][2];
void turn(int a);
int backnum(int n, int isTurn);
int check();
int main(){

	freopen("input.txt","r",stdin);
	memset(cache, -1, sizeof(cache));
	string buf;	
	cin>>N;
	for(int i = 0 ; i < N; i++){
		cin>>buf;
		for(int j = 0 ; j < N; j++){
			array[i][j] = (buf[j] == 'H');
		}
	}

	cout<<min(backnum(0,0),backnum(0,1))<<endl;
	return 0;
}

int backnum(int n,int isTurn){
	if(n == 2*N-1) return check();

	int& ret = cache[n][isTurn];

	if(ret != -1) return ret;
	
	if(isTurn == 1){
		turn(n);
	}

	return ret = min(backnum(n+1, 0), backnum(n+1,1));

	// return ret += check();
}

void turn(int a){
	if(a <=N-1){
		for(int i = 0 ; i < N; i++){
			array[a][i]!=array[a][i];
		}
	}
	else{
		for(int i = 0; i < N ;i++){
			array[i][a]!=array[i][a];
		}

	}
}
int check(){
	int cnt = 0;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			cnt+=(array[i][j]==0);
		}
	}
	return cnt;
}