#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int r[1001], c[1001];
double optimal();
bool decision(double x);
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n>>k;
		for(int i = 0 ; i < n; i++){
			cin>>r[i]>>c[i];
			// cout<<r[i]<<" "<<c[i]<<"     ";
		}
		// cout<<endl;
		printf("%.8f\n",optimal() );
	}


	return 0;
}

double optimal(){
	double lo = -0.01 , hi = 1.1;

	for(int it = 0; it < 100; it++){
		double mid = (lo + hi)/2;
		if(decision(mid)){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	return lo;
}
bool decision(double x){
	vector<double> v;
	for(int i = 0; i < n; i++){
		v.push_back(x * c[i] - r[i]);
	}

	sort(v.begin(), v.end());

	double s = 0;

	for(int i = n - 1; i >= n - k; i--)
		s += v[i];
	// cout<<s<<endl;
	return s >= 0;
}