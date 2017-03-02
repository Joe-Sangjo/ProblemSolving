#include <iostream>
#include <cstdio>

using namespace std;

int N, K;
int A[11];

int main(){
	freopen("input.txt","r",stdin);
	cin>>N>>K;

	int num = 0; 
	for(int i = 0 ; i < N ; i++){
		cin>>A[i];
	}
	for(int i =  N - 1; i >= 0; i--){
		if(A[i] <= K){
			
			num += K / A[i];
			K %= A[i];
		}
	}
	cout<<num<<endl;

	return 0;
}