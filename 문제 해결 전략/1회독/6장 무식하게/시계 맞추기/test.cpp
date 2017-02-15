#include <iostream>

using namespace std;

long long fastSum(long long n){
	if(n == 1) return 1;
	if(n % 2 == 1) return fastSum(n-1) + n;
	return 2*fastSum(n/2) + (n/2)*(n/2);
}
int main(){

	cout<<fastSum(1000000000)<<endl;




	return 0;
}

