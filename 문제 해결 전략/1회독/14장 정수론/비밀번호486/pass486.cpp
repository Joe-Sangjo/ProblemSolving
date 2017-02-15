#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n, lo, hi;
// int maxHi;
int test[50][3];
int divisor[10000001];
void getDivisorNum();
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;
	hi = 0;
	for(int test_case = 0; test_case < TC; test_case++){
		cin>>test[test_case][0]>>test[test_case][1]>>test[test_case][2];
		hi = max(hi, test[test_case][2]);
	}
	
	memset(divisor, 0, sizeof(divisor));
	
	getDivisorNum();
	for(int test_case = 0; test_case < TC; test_case++){
		int num = 0;
		for(int i = test[test_case][1]; i <= test[test_case][2]; i++){
			if(test[test_case][0] == divisor[i]){
				num++;
			}
		}
		cout<<num<<endl;
	}
	// int array[100];
	// memset(array, -1, sizeof(array));
	// cout<<array[1]<<endl;
	// cout<<-28%100<<endl;
	return 0;
}

void getDivisorNum(){
	int sq = sqrt(hi);
	for(int i = 1; i<= hi; i++){
		for(int j = 1; i*j <= hi; j++){
			divisor[i*j]++;
		}
		// cout<<i<<endl;
		// for(int k = 1; k <= i; k++){
		// 	cout<<divisor[k]<<" ";
		// }
		// cout<<endl;
	}
	// cout<<endl;
}