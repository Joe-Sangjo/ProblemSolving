#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int N, K;
int L[5001], M[5001], G[5001];
bool decision(int x);
int optimial();
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC ; test_case++){
		cin>>N>>K;
		for(int i = 0 ; i < N ;i++){
			cin>>L[i]>>M[i]>>G[i];
		}
		cout<<optimial()<<endl;
	}

	return 0;
}

bool decision(int x){
	int cnt = 0;

	for(int i = 0 ; i < N ; i++){
		int dist = L[i] - M[i];
		if(x >= dist)
			cnt += (min(x, L[i]) - dist)/G[i] + 1;
	}


	return cnt >= K;
}

int optimial(){
	int lo = 0, hi = 8080000;

	for(int it = 0 ; it < 100; it++){

		int mid = (lo + hi) / 2;

		if(decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;

}