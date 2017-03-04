#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>


using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int N;
	int L[100001], R[100001];

	cin>>N;

	for(int i = 0 ;i < N; i++){
		cin>>L[i]>>R[i];

	}
	// int asdf[100000][100000/64];

	unsigned long long isFlower[N][(100000+63)/64];
	memset(isFlower, 0 ,sizeof(isFlower));

	cout<<0<<endl;
	for(int day = 1; day < N; day++){
		int n = 0;
		for(int before = day - 1; before >= 0; before--){
			if(R[day] > L[before] && R[day] < R[before] && (isFlower[before][R[day]>>6] & (1 <<(R[day] & 63) ) ) == 0  ){
				n++;

				isFlower[before][R[day]>>6] |= (1 << (R[day] & 63));
				// cout<<isFlower[before][R[day] >> 6]<<endl;
				// cout<<day<<"  "<<before<<"  "<<"RR "<<R[day]<<endl;
			}
			if(L[day] < R[before] && L[day] > L[before] && (isFlower[before][L[day]>>6] & (1 <<(L[day] & 63) ) ) == 0 ){
				n++;
				isFlower[before][L[day]>>6] |= (1 << (L[day] & 63));
				// cout<<isFlower[before][L[day] >> 6]<<endl;
				// cout<<day<<"  "<<before<<"  "<<"LL "<<L[day]<<endl;
			}
		}
		cout<<n<<endl;
	}



	return 0;
}