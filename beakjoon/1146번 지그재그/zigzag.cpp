#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 1000000;
int n;
int standingline(int idx,int pre_people, int now_people);
// int cache[101][101][101];
bool isStanding[101];
int main(){
	// cin>>n;
	n = 5;
	// memset(cache, -1, sizeof(cache));
	memset(isStanding, false, sizeof(isStanding));
	int ret = 0;

	for(int i = 1; i<= n; i++){
		for(int j = 1; j <= n ; j++){
			if( i != j){
				isStanding[i] = isStanding[j] = true;
				ret += standingline(2,i,j) % MOD;
				isStanding[i] = isStanding[j] = false;
			}
		}
	}
	cout<<ret % MOD<<endl;
	return 0;
}


int standingline(int idx, int pre_people, int now_people){
	if(idx == n) return 1;


	int ret = 0;

	if(pre_people < now_people){
		for(int i = now_people - 1; i >=1; i--){
			if(!isStanding[i]){
				isStanding[i] = true;
				ret += standingline(idx + 1, now_people, i) % MOD;
				isStanding[i] = false;
			}
		}
	}
	else{
		for(int i = now_people + 1; i <= n; i++){
			if(!isStanding[i]){
				isStanding[i] = true;
				ret += standingline(idx + 1, now_people, i) % MOD;
				isStanding[i] = false;
			}
		
		}
	}
	return ret % MOD;
}