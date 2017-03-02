#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int N;
int array[2200][2200];
int a, b, c;
void cutting(int y, int x, int size);
int check(int y, int x, int size);
int main(){

	freopen("input.txt","r",stdin);

	cin>>N;
	for(int i = 1 ; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin>>array[i][j];
		}
	}

	a = b = c = 0;

	cutting(1,1,N);

	cout<<a<<endl<<b<<endl<<c<<endl;

	return 0;
}

void cutting(int y, int x, int size){
	
	if(size == 1){
		if(array[y][x] == -1){
			a++;
		}
		else if(array[y][x] == 0){
			b++
;		}
		else{
			c++;
		}
		return;
	}
	int cc = check(y,x,size);

	if(cc == -1){
		a++;
	}
	else if(cc == 0){
		b++;
	}
	else if(cc == 1){
		c++;
	}
	else{
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cutting(y + i*(size/3), x + j*(size/3), size/3);
			}
		}
	}
	return;
}

int check(int y, int x, int size){

	int tmp = array[y][x];
	bool c = true;
	bool aa= true;
	for(int i = y; i < y + size ; i++){
		for(int j = x; j < x + size ; j++){
			if(tmp != array[i][j]){
				c = aa = false;
				break;
			}
		}
		if(!aa) break;
	}

	if(c) return tmp;
	else	return -100;
}