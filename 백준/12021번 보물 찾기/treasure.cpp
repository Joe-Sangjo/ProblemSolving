#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){

	double a[2], b[2];

	// cin>>a[0]>>b[0];

	a[0] = 10;
	b[0] = 5;

	while(1){

		a[1] = (a[0] + b[0]) / 2;
		b[1] = (2 * a[0] * b[0]) / (a[0] + b[0]);

		if(abs(a[0] - a[1]) <= pow(10,-7) && abs(b[0] - b[1]) <= pow(10,-7)){
			break;
		}
		a[0]= a[1];
		b[0] = b[1];
	}


	printf("%.7f %.7f\n",a[1],b[1] );
	return 0;
}