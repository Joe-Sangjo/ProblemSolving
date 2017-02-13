#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
int N,K,M;
int length[51];
int like[51];

double T[51][51];
double C[5][51];


int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N>>K>>M;

		for(int i = 0; i < N; i++){
			cin>>length[i];
		}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin>>T[i][j];
			}
		}

		for(int i = 0; i < M; i++){
			cin>>like[i];
		}
		C[0][0] = 1.0;
		for(int time = 1; time <= K; time++){
			for(int song = 0; song < N; song++){
				double& prob = C[time % 5][song];
				prob = 0;
				for(int last = 0; last < N; last++)
					prob += C[(time - length[last]) % 5][last] * T[last][song];
			}
		}
		vector<double> ret(N);

		for(int song = 0; song < N; song++){
			for(int start = K - length[song] + 1; start <= K; start++)
				ret[song] += C[start % 5][song];

		}
		for(int li = 0; li < M; li++){
			cout<<ret[li]<<" ";
		}
		cout<<endl;

	}


	return 0;
}