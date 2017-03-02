#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int petch[1001];
int main(){
	freopen("input.txt","r",stdin);

	cin>>N;
	for(int i = 0 ; i < N; i++){
		cin>>petch[i];
	}
	sort(petch, petch + N);

	int result = 0;

	for(int i = N - 1; i >= 0; i--){
		result += (N - i) * petch[i];
	}
	cout<<result<<endl;

	return 0;
}