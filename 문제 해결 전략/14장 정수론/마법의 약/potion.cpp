#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int r[200], p[200];
// int ratio[101];
double eachratio[200];
int gcd(int p, int q);
int allgcd();
void geteachratio();
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>r[i];
		}
		for(int i = 0; i < n; i++){
			cin>>p[i];
		}
		geteachratio();

		// for(int i = 0; i < n ; i++){
		// 	cout<<eachratio[i]<<" ";
		// }
		// cout<<endl<<endl;

		double check = -1.0;

		for(int i = 0; i < n; i++){
			check = max(check, p[i]/eachratio[i]);

		}
		// cout<<check<<endl;

		if(check - (int)check == 0){
			for(int i = 0; i < n; i++){
				cout<<eachratio[i] * check - p[i]<<" ";
			}
		}
		else{
			int rr = (int)(check + 1.0);
			for(int i = 0; i < n ; i++){
				cout<<eachratio[i] * rr - p[i]<<" ";
			}
		}
		cout<<endl;
	}


	return 0;
}

int gcd(int p, int q){
	if(q == 0) return p;
	return gcd(q, p % q);
}
int allgcd(){
	int g = r[0];
	for(int i = 1; i < n; i++){
		g = gcd(g, r[i]);
	}
	return g;
}
void geteachratio(){
	int g = allgcd();
	for(int i = 0; i < n; i++){
		eachratio[i] = r[i] / g;
	}
}