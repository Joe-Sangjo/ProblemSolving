#include <iostream>
#include <cmath>
using namespace std;
int* getdecimal(int a[32]);
int main(){

	int a[32] = {1,1,0,0,0,0,1,0,    0,1,0,1,0,1,0,1,    1,0,1,0,0,0,0,0,    1,0,1,1,0,0,0,0};
				
	int *b=getdecimal(a);
	for(int i=0;i<4;i++){
		cout<<endl<<*(b+i)<<endl;
	}

	delete b;
}
int* getdecimal(int a[32]){
	int *b=new int[4];

	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			*(b+i)+=a[8*i+(7-j)]*pow(2,j);
		}
	}

	return b;
}