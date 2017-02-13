#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long cnt;
void counting(int n);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;
	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;
		cnt = 0;
		counting(n);
		cout<<cnt%1000000007<<endl;

	}
	return 0;
}

void counting(int n){
	if(n == 0){
		cnt++;
		return;
	}

	if( n < 0) return;

	counting(n-1);
	counting(n-2);
}