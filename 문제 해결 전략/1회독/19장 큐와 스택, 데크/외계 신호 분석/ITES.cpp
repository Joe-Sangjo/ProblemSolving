#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int K, N;
unsigned int A[2];
// unsigned const int MOD = (1<<32); 
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;
	// TC = 1;
	while(TC--){
		cin>>K>>N;

		A[0] = 1983;
		int sum = 0;
		int n = 0;
		deque<int> b;
		for(int i = 0; i < N ;i++){
			A[1] = (A[0] * 214013 + 2531011);
			b.push_back(A[0] % 10000 + 1);

			sum += A[0] % 10000 + 1;

			while(sum > K){
				sum -= b[0];
				b.pop_front();

			}


			if(sum == K)	n++;


			A[0] = A[1];			
		}
		cout<<n<<endl;

	}


	return 0;
}