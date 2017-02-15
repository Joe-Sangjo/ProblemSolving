#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int FenceNum;
int Fence[20001];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);
	int TC;
	cin>>TC;
	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>FenceNum;
		memset(Fence, 0, 20000*sizeof(int));
		for(int i = 0 ; i < FenceNum; i++)
			cin>>Fence[i];
		max(2,3,4);
		
		

	}
	return 0;
}