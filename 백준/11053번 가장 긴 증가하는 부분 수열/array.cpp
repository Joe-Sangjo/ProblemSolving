#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;



int N;
int array[1001];
int cache[1001];
int makearray(int start);
int main(){
	freopen("input.txt","r",stdin);
	cin>>N;
	for(int i = 0 ; i < N;i++)
		cin>>array[i];

	memset(cache, -1, sizeof(cache));
	int ret = 0;
	for(int i = 0 ; i < N; i++){
		ret = max(ret, makearray(i));
	}
	cout<<ret<<endl;
	return 0;
}


int makearray(int start){


	int& ret = cache[start];

	if(ret != -1) return ret;

	ret = 1; 

	for(int i = start + 1; i < N; i++){
		if(array[start] < array[i])
			ret = max(ret, makearray(i) + 1);
	}
	return ret;
}