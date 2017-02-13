#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int m, q;
string word[501];
double B[501];
double T[501][501];
double M[501][501];
int n[101];
string voca[101];
int main(){
	freopen("input.txt","r",stdin);
	cin>>m>>q;

	for(int i = 0; i < m; i++){
		cin>>word[i];
		// cout<<word[i]<<" ";
	}
	// cout<<endl;
	for(int i = 0; i < m; i++){
		cin>>B[i];
		// cout<<B[i]<<" ";
	}
	// cout<<endl;

	for(int i = 0; i < m ;i ++){
		for(int j = 0 ; j < m; j++){
			cin>>T[i][j];
			// cout<<T[i][j]<<" ";
		}
		// cout<<endl;
	}

	for(int i = 0 ; i < m ;i++){
		for(int j = 0; j < m; j++){
			cin>>M[i][j];
			// cout<<M[i][j]<<" ";
		}
		// cout<<endl;
	}


	for(int i = 0; i < q; i++){
		cin>>n[i]; 
		// cout<<n[i]<<" ";
		for(int j = 0; j < n[i]; j++){
			cin>>voca[j];
			// cout<<voca[j]<<" ";
		}
		// cout<<endl;
	}
























	

	return 0;
}