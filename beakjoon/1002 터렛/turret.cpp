#include <iostream>
#include <cstdio>
using namespace std;



int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0 ;test_case < TC; test_case ++){
		int x1, y1, r1, x2, y2, r2;

		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		
		// cout<<x1<<" "<<y1<<" "<<r1<<" "<<x2<<" "<<y2<<" "<<r2<<endl;
		
		if(x1 == x2 && y1 == y2 && r1 == r2){
			cout<<-1<<endl;
			continue;
		}
		int d = (x2 -x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		// cout<<d<<endl;
		if(d > (r1 + r2)*(r1 + r2) ){
			cout<<0<<endl;
		}
		else if( d == (r1 + r2) * (r1 + r2) ) {
			cout<<1<<endl;
		}
		else if(d < (r1 + r2) * (r1 + r2) && d > (r2 - r1) * (r2 -r1)){
			cout<<2<<endl;
		}
		else if((r2 - r1) * (r2 - r1) == d){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}

	}


	return 0;
}