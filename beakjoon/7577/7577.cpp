#include <iostream>
#include <cstdio>

using namespace std;

int k, n;
int ProbeX[1001], ProbeY[1001], ProbeR[1001];

int main(){
	freopen("input.txt","r",stdin);

	cin>>k>>n;
	for(int i = 0; i < n; i++){
		cin>>ProbeX[i]>>ProbeY[i]>>ProbeR[i];
		// cout<<ProbeX[i]<<" "<<ProbeY[i]<<" "<<ProbeR[i]<<endl;
	}

	


	return 0;
}