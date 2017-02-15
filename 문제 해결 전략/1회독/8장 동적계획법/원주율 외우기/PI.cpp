#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define INF 2100000000
using namespace std;

string n; 
int cache[10001];
int PI(int i);
int retvalue(string a);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>> TC;


	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n;
		memset(cache, -1, sizeof(cache));
			cout<<PI(0)<<endl;


		// cout<<endl;
	}

	return 0;
}

int PI(int i){
	// cout<<i<<endl;
	if(i == n.size()) return 0;

	if(i > n.size()) return INF;

	int& ret = cache[i];

	if(ret!=-1) return ret;

	ret = INF;

	ret = min(ret, retvalue(n.substr(i,3)) + PI(i+3));
	ret = min(ret, retvalue(n.substr(i,4)) + PI(i+4));
	ret = min(ret, retvalue(n.substr(i,5)) + PI(i+5));		


	return ret;
}


int retvalue(string a){
	bool check = true;

	for(int i = 0 ; i < a.size()-1 ; i++){
		if(a[i] != a[i+1]){
			check = false;
			break;
		}
	}
	if(check) return 1;

	check = true;

	for(int i = 0; i < a.size() -1 ; i++){
		if(a[i] + 1 != a[i+1]){
			check = false;
			break;
		}
	}

	if(check) return 2;

	check = true;

	for(int i = 0; i < a.size() -1 ; i++){
		if(a[i] -1 != a[i+1]){
			check = false;
			break;
		}
	}

	if(check) return 2;

	check = true;

	for(int i = 2 ; i < a.size(); i+=2){
		if(a[0]!=a[i]){
			check = false;
			break;
		}
	}
	for(int i = 3; i < a.size(); i+=2){
		if(a[1]!=a[i]){
			check = false;
			break;
		}
	}

	if(check) return 4;

	check = true;
	for(int i = 1; i < a.size()-1 ; i++){
		if(a[0]-a[1] != a[i]-a[i+1]){
			check = false;
			break;
		}
	}

	if(check) return 5;

	return 10;
}