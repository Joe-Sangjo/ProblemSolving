#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N, D, P, T, Q;
int Qbuf[51];
int destination;
double village[51][51];

double cache[200][200];
double DUNIVAL(int days, int now);
void initailize();
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);


	int TC; cin>>TC;
	int cnt;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N>>D>>P;
		for(int i = 0 ; i < N; i++){
			cnt = 0 ;
			for(int j = 0 ; j < N ; j++){
				cin>>village[i][j];
				cnt += village[i][j];
			}
			for(int j = 0; j < N ; j++){
				village[i][j]/=cnt;
			}
		}

		cin>>T;
		for(int i = 0 ; i < T ; i++)
			cin>>Qbuf[i];
		
		for(int j = 0; j < T ; j++){
			destination = Qbuf[j];
			memset(cache, -1, sizeof(cache));
			// initailize();
			double pro = 0;

			for(int i = 0 ; i < N ;i++){
				pro += village[P][i]*DUNIVAL(1, i);
			}
			printf("%0.8f ", pro);

		}
		cout<<endl;
	}
	return 0;
}

double DUNIVAL(int days, int now){

	if(days == D) return (now == destination ? 1.0 : 0.0);

	double& ret = cache[days][now];
	if(ret > -0.5) return ret;

	ret = 0.0;

	for(int i = 0 ; i < N; i++){
		if(village[now][i] != 0){
			ret += village[now][i] * DUNIVAL(days + 1, i);
		}
	}
	return ret;
}

void initailize(){
	for(int i = 0 ; i < 200; i++){
		for(int j = 0 ; j < 200 ; j++){
			cache[i][j] = -1;
		}
	}
}