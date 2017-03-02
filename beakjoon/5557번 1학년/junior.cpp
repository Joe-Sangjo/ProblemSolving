#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long junior(int idx, int result);
int N;
int R;
int data[101];
long long cache[101][101];
int main(){
	freopen("input.txt","r",stdin);
	cin>>N;
	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < N-1; i++)
		cin>>data[i];
	cin>>R;
	cout<<junior(0,data[0])<<endl;
	// cout<<data[N-1]<<endl;
	// cout<<R<<endl;
}

long long junior(int idx, int result){
	// cout<<idx<<"  "<<result<<endl;
	if(idx == N-2 ) return result == R;

	long long& ret = cache[idx][result];

	if(ret != -1) return ret;

	ret = 0;

	if(result + data[idx + 1] <= 20){
		ret += junior(idx + 1, result + data[idx + 1]);
	}
	if(result - data[idx + 1] >= 0){
		ret += junior(idx + 1, result - data[idx + 1]);
	}
	return ret;
}