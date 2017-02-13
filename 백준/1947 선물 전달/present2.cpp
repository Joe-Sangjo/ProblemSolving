#include <iostream>
using namespace std;
int main(){
	unsigned long a[10];
	unsigned long b[5];
	a[1]=0; a[2]=1; a[3]=2; a[4] = 9;
		    b[2]=1; b[3]=2; b[4] = 3;
	int N;
	// cin>>N; 
	N=4;
	if(N>4){
		for(int i=5;i<=N;i++){
			// a[i-3]=a[i-2];
			// a[i-2]=a[i-1];
			// b
			b[5]=(i-2)*b[4]+a[3];
			a[5]=(i-1)*b[5];
			a[3]=a[4];
			a[4]=a[5];
			b[4]=b[5];
		}
	}
	cout<<a[N]%1000000000<<endl;
	// cout<<N<<endl;
	return 0;
}

