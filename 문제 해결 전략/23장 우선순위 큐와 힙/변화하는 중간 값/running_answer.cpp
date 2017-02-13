#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

const int MOD = 20090711;
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	scanf("%d", &TC);

	while(TC--){
		int N, a, b;
		scanf("%d %d %d", &N, &a, &b);
		long long A[2];
		A[0] = 1983;

		long long ret = 0;
		priority_queue<int, vector<int>, less<int> > maxHeap;
		priority_queue<int, vector<int>, greater<int> > minHeap;

		for(int cnt = 1; cnt <= N; cnt++){
			A[1] = ((A[0]*a%MOD) + b) % MOD;
			
			if(maxHeap.size() == minHeap.size())
				maxHeap.push(A[1]);
			else
				minHeap.push(A[1]);

			if(!minHeap.empty() && !maxHeap.empty() &&
				minHeap.top() < maxHeap.top()){
				int a = maxHeap.top(), b = maxHeap.top();
				maxHeap.pop(); minHeap.pop();
				maxHeap.push(b);
				minHeap.push(a);
			}
			ret = (ret + maxHeap.top()) % MOD;
			A[0] = A[1];
		}
		printf("%lld\n", ret%MOD);
	}




	return 0;
}