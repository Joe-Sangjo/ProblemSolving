#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N, E;
int S[101];
bool decision(int num);
int optimize(int num);
int main(){

	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N>>E;
		for(int i = 0 ; i < N; i++){
			cin>>S[i];
			// cout<<S[i]<<" ";
		}
		// cout<<endl;
		sort(S, S + N);




	}




	return 0;
}

bool decision(int num){


}
int optimize(int num){

	
}