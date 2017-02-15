#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int N, K, M;
int length[51];
int like[51];
int m;
double T[51][51];
double cache[51][1000001];
double play(int music, int minute);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N>>K>>M;
		int minum_length = 987654321;
		for(int i = 0; i < N; i++){
			cin>>length[i];
			minum_length = min(minum_length, length[i]);
			// cout<<length[i]<<" ";
		}
		// cout<<endl;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin>>T[i][j];
				// cout<<T[i][j]<<" ";
			}
			// cout<<endl;
		}
		// cout<<endl;
		for(int i = 0; i < M; i++){
			cin>>like[i];
			// cout<<like[i]<<" ";
		}
		// cout<<endl;
		
		for(int li = 0; li < M; li++){
			memset(cache, -1.0, sizeof(cache));
			m = like[li];
			// cout<<m<<" ";
			printf("%.8lf ",play(0,0));
		}
		cout<<endl;

	}

	return 0;
}

double play(int music, int minute){
	// cout<<music<<" "<<minute<<endl;
	// if(minute > K) return -10.0;

	double& ret= cache[music][minute];

	if(ret > -0.5) return ret;

	ret = 0;

	for(int next = 0; next < N; next++){
		if(minute + length[music] > K){
			return music == m;
		}
		else{
			ret += T[music][next] * play(next, minute + length[music]);
		}
	}
	return ret;
}