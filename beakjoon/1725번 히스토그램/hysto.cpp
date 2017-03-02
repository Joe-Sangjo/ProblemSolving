#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int N; 	cin>>N;
	int buf;
	int h = 0;
	int sum = 0;
	deque<int> b;
	for(int i = 0; i < N; i++){
		cin>>buf;
		if(buf >= h){
			sum += h;
		}
		else{

		}
	}




	return 0;
}