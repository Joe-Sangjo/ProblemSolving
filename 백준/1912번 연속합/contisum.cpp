#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long long arr[100001];
long long cache[100001];
long long n, ret;
int main(){
	freopen("input.txt","r",stdin);
	cin>>n;

	for(int i = 0 ; i < n; i++){
		cin>>arr[i];
	}
	cache[0] = arr[0];
	ret = cache[0];
	for(int i = 1;i<n;i++){
		cache[i] = max(cache[i-1] + arr[i], arr[i]);
		ret = max(cache[i], ret);
	}
	cout<<ret<<endl;


	return 0;
}