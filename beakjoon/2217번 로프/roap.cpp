#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int roap[100001];
int main(){
	freopen("input.txt","r",stdin);
	cin>>N;
	for(int i = 0; i < N; i++)
		cin>>roap[i];

	sort(roap, roap + N);

	int max_mass = 0;

	for(int i = 0 ; i < N; i++){
		max_mass = max(max_mass, (N-i)*roap[i]);
	}
	cout<<max_mass<<endl;
	return 0;
}