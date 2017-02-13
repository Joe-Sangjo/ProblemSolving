#include <iostream>
#include <cstdio>

using namespace std;

int n;
int cache[101];
int asym(int width);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n;

	}

	return 0;
}

int asym(int width){
	if(n == 1) return 0;

	if(n == 2) return 0;

	if(n == 3) return 3;

	if(n == 4) return 2;

	int& ret = cache[width];
	
}