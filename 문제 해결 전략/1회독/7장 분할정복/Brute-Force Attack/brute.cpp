#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int MOD = 1000000007;
int A, B, N;
long long count(int start, int end);
long long 
int main(){
	freopen("input.txt","r",stdin);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case ++){
		cin>>A>>B>>N;
		cout<<count(A,B) % MOD<<endl;



	}
	return 0;
}

long long pow(int n){

}