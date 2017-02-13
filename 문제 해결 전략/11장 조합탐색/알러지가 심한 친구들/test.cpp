#include <iostream>

using namespace std;

int main(){
	int a = 10;

	for(int i = 0; i < 5; i++){
		if(!(a & (1<<i))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}


	return 0;
}