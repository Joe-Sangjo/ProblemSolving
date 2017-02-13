#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double cross(long long x1, long long y1, long long x2, long long y2);

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int N;
	long long x[10001], y[10001];

	cin>>N;


	for(int i = 0; i < N; i++){
		cin>>x[i]>>y[i];
	}

	double area = 0;

	for(int i = 0; i < N ;i++){
		int j = (i + 1) % N;
		area += cross(x[i], y[i], x[j], y[j]);
	}
	printf("%.1f\n",fabs(area)/2);
	return 0;
}

double cross(long long x1, long long y1, long long x2, long long y2){
	return (double)(x2*y1 - x1*y2);
}