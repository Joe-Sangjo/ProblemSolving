#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 2100000000;
int N;
void turn(bool**& array,int n);
int solve(bool**& array,int n);

int main(){

	char buf;
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	cin>>N;
	bool **array; 
	array = new bool*[N];
	
	for(int i = 0; i < N ; i++ )
		array[i] = new bool[N];

	for(int i = 0 ; i < N ; i ++)
		for(int j = 0 ; j < N ; j++){
			cin>>buf;
			if(buf == 'H')
				array[i][j] = true;
			else{
				array[i][j] = false;
			}
		}

	// for(int i = 0 ; i < N ; i++){
	// 	for(int j = 0 ; j < N ; j++)
	// 	{
	// 		cout<<array[i][j];
	// 	}
	// 	cout<<endl;
	// }
	cout<<solve(array,0)<<endl;
	// turn(2);
	// cout<<endl;
	// for(int i = 0 ; i < N ; i++){
	// 	for(int j = 0 ; j < N ; j++)
	// 	{
	// 		cout<<array[i][j];
	// 	}
	// 	cout<<endl;
	// }


	for(int i = 0 ; i < N ; i ++ )
		delete[] array[i];
	delete []array;


	return 0;
}



void turn(bool**& array,int turnN){
	if(turnN<N){//turn Row
		for(int i = 0 ; i < N; i++)
			array[turnN][i]=!array[turnN][i];
	}
	else{//turn Col
		turnN-=N;
		for(int i = 0 ; i < N; i++)
			array[i][turnN]=!array[i][turnN];
	}
}
int check(bool**& array){
	int cnt = 0;
	for(int i = 0 ; i < N ;i++){
		for(int j = 0; j < N; j++){
			if(array[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

int solve(bool**& array, int n){
	if(n==2*N) return check(array);

	int cnt = INF;

	for(int i = 0 ; i < 2; i++){
		cnt = min(cnt, solve(array, n+1));
		// if(i==1)
		turn(array,n);
	}
	return cnt;

}