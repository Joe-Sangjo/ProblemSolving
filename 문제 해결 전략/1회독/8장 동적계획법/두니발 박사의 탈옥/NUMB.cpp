#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int N, D, P, T, Q;
int Qbuf[51];
double village[51][51];
// double cache[51][51];
double prob[51];
void DUNIVAL(int days, int to, double p);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);


	int TC; cin>>TC;
	int cnt;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N>>D>>P;
		// memset(cache, -1, sizeof(cache));
		memset(prob, 0, sizeof(prob));
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
		

		// for(int i = 0 ; i < N ;i++){
		// 	for(int j = 0 ; j < N; j++){
		// 		cout<<village[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl<<endl;
		// cout<<P<<endl;

		for(int i = 0 ; i < N; i++){
			if(village[P][i] != 0)
				DUNIVAL(1, i, village[P][i]);
		}



		for(int i = 0 ; i < T ;i++){
			printf("%0.8f ",prob[Qbuf[i]] );
		}
		cout<<endl;
	}
	return 0;
}

void DUNIVAL(int days, int to, double p){
	// cout<<days<<endl;
	if(days == D)	{
		prob[to] += p;
		return;
	}
	for(int i = 0 ; i < N ; i++){
		if(village[to][i] != 0)
			DUNIVAL(days + 1 , i, p*village[to][i]);
	}
}