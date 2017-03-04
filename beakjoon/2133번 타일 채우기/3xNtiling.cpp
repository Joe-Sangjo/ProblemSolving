#include <iostream>

using namespace std;


int main(){

	long long tile[35];

	tile[0] = 1;
	tile[2] = 3;
	int N;
	cin>>N;
	// N = 12;
	if( N % 2 == 1){
		cout<<0<<endl;
		return 0;
	}
	for(int i = 4; i <= 35 ; i+= 2){
		tile[i] = 3*tile[i-2];
		for(int j = 4; j <=i ; j+= 2){
			tile[i] += 2 * tile[i-j];
		}
	}

	cout<<tile[N]<<endl;



	return 0;
}