#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
const int MOD = 20090711;
void swap(int& a, int& b){
	int temp = b;
	b = a;
	a = temp;
}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	scanf("%d",&TC);
	// TC = 1;
	while(TC--){
		int N, a, b;	
		scanf("%d %d %d ",&N, &a, &b);

		vector<long long> array;
		long long A[2];
		A[0] = 1983;
		int ret = 0;
		for(int i = 0 ; i < N; i++){
			array.push_back(A[0]);
			int j = i;
			while(j > 0 && array[j - 1] > array[j]){
				swap(array[j-1], array[j]);
				j--;
			}
			if(i % 2){
				ret += min(array[i / 2], array[i / 2 + 1]);
			}
			else{
				ret += array[i / 2];
			}
			ret %= MOD;
			A[1] = (A[0] * a) % MOD;
			A[1] += b;
			A[1] %= MOD;
			A[0] = A[1];
			// cout<<A[1]<<" ";
		}
		// cout<<endl;
		cout<<ret<<endl;
	}





	return 0;
}