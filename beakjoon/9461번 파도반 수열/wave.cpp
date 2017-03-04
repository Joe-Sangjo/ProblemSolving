#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
long long data[200];
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	data[1] = 1; data[2] = 1; data[3] = 1; data[4] = 2; data[5] = 2;
	data[6] = 3;
	for(int i = 7; i <=200; i++){
		data[i] = data[i-1] + data[i-5];
	}
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N;
		cout<<data[N]<<endl;


	}




	return 0;
}