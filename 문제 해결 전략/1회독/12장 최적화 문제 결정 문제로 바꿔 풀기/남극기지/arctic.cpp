#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

int N;
double x[101], y[101];
bool isCom[101];
double d[101][101];
bool decision(double dist);
double optimal();

int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>N;
		for(int i = 0 ; i < N; i++){
			cin>>x[i]>>y[i];
			// cout<<x[i]<<" "<<y[i]<<endl;
		}
		// cout<<endl;
		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < N; j++){
				d[i][j] = sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
			}
		}
		printf("%.2f\n",optimal() );
	}



}
double optimal(){
	double lo = 0, hi = 1000*sqrt(2);

	for(int it = 0; it < 100; it++){
		double mid = (lo + hi) / 2.0;

		if(decision(mid)){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	return hi;
}

bool decision(double dist){

	int ableCommunicate = 0;
	
	memset(isCom, false, sizeof(isCom));

	isCom[0] = true;

	queue<int> q;

	q.push(0);

	// int seen = 0;

	while(!q.empty()){
		int here = q.front();
		q.pop();
		ableCommunicate++;
		for(int i = 0 ; i < N; i++){
			if(!isCom[i] && d[here][i] <= dist){
				isCom[i] = true;
				q.push(i);
			}
		}
	}
	return ableCommunicate == N;
}