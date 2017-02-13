#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int M, W;
int man[1001], woman[1001];
int cache[1001][1001];
int couple(int m, int w);
int main(){
	freopen("input.txt","r",stdin);
	cin>>M>>W;
	memset(cache, -1, sizeof(cache));
	if(M <= W){
		for(int i = 0 ; i < M; i++)
			cin>>man[i];

		for(int i = 0 ; i < W; i++)
			cin>>woman[i];
	}
	else{
		for(int i = 0 ; i < M; i++){
			cin>>woman[i];
		}

		for(int i = 0; i < W; i++){
			cin>>man[i];
		}
		int temp = W;
		W = M;
		M = temp;

	}
	sort(man, man + M); sort(woman, woman + W);
	for(int i = 0 ; i < M; i++){
		cout<<man[i]<<" ";
	}
	cout<<endl;

	for(int i = 0; i < W; i++){
		cout<<woman[i]<<" ";
	}
	cout<<endl;

	int ret = 987654321;
	for(int i = 0; i <= W - M; i++){

		ret = min(ret, couple(0,i));
	}

	cout<<ret<<endl;

	return 0;
}
int couple(int m, int w){
	// cout<<m<<" "<<w<<endl;
	if(m == M - 1) return abs(man[m] - woman[w]);

	int& ret = cache[m][w];

	if(ret != -1) return ret;

	ret = 987654321;

	for(int i = w + 1; i <= W - M + m + 1; i++){
		ret = min(ret, couple(m + 1, i) + abs(man[m] - woman[w]));
	}

	return ret;
}
