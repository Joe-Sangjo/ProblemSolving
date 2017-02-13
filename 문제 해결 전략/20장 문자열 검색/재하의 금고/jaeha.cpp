#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int N, length;
string pass[101];
int cw(string now, string next);
int ccw(string now, string next);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	while(TC--){
		cin>>N;
		// cout<<N<<endl;
		for(int i = 0; i <= N; i++){
			cin>>pass[i];
			// cout<<pass[i]<<endl;
		}
		length = pass[0].length();

		int total = 0;

		for(int i = 0; i < N ; i++){
			int num;
			if(i % 2 == 1){
				num = cw(pass[i],pass[i + 1]);
			}
			else{
				num = ccw(pass[i], pass[i + 1]);
			}
			// cout<<"       "<<num<<endl;
			total += num;
		}
		cout<<total<<endl;

	}


	return 0;
}

int cw(string now, string next){
	int num = 0;
	while(now != next){
		char fi = now[0];
		now.erase(0,1);
		now += fi;
		num++;
	}
	return num;
}

int ccw(string now, string next){
	int num = 0;
	while(now != next){
		string ne;
		ne += now[length - 1];
		now.erase(length - 1, 1);
		ne += now;
		now = ne;
		num++;
	}
	return num;
}