#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int INF = 987654321;
int N, E, Se;
int S[101];
int upgrade(int n, int selected);
int cache[101][101];
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC-2;test_case++){
		cin>>N>>E;
		for(int i = 0 ; i < N ; i++)
			cin>>S[i];
		int ret = INF;
		for(Se = 1; Se <= N; Se++){
			memset(cache, -1, sizeof(cache));
			for(int i = 0 ; i <= N - Se; i++){
				ret = min(ret, upgrade(i,0));
			}
		}
		if(ret >= INF)
			cout<<"FULL"<<endl;
		else
			cout<<ret<<endl;
	}




	return 0;
}

int upgrade(int n, int selected){
	cout<<n<<"   "<<selected<<"    "<<Se<<endl;
	if(selected == Se) return 0;

	int& ret = cache[n][selected];

	if(ret != -1) return ret;

	ret = INF;
	int temp;
	for(int idx = n + 1; idx<= N - Se +selected; idx++){
		temp = upgrade(idx, selected +1);
		if((temp + S[n])*2 >= E){
			ret = min(ret, temp + S[n]);
		}
	}
	return ret;

}