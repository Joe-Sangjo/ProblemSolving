#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool isPalin(const string a, int start);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; 		cin>>TC;
	string in;
	while(TC--){
		cin>>in;
		int n = in.size();
		int ret = n;
		for(int i = 0; i < n ; i++){
			if(isPalin(in, i)){
				ret += i;
				break;
			}
		}
		cout<<ret<<endl;

	}

	return 0;
}


bool isPalin(const string a, int start){
	int n = a.size();
	bool check = true;
	
	for(int i = 0; i + start <= n - 1 - i; i++){
		if(a[i + start] != a[n - 1 - i]){

			check = false;

			break;

		}

	}
	return check;
}