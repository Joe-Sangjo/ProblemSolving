#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
int N, m, M, T, R;
int minMinute = 0x3f3f3f3f;
int cache[201][201];

//return 값은 최소 운동, breath는 지금 맥박수, 
//exerMinute는 운동한 시간 수 
int BruteForce(int breath, int exerMinute){
	// cout<<breath<<"  "<<exerMinute<<endl;
	if(exerMinute == N){
		return 0;
	}

	int& ret = cache[breath][exerMinute];
	if(ret != -1) return ret;
	
	ret = 0x3f3f3f3f;
	
	//운동한 경우
	if(breath + T <= M){
		ret = min(ret, BruteForce(breath + T, exerMinute + 1) + 1);
	}

	//휴식의 경우
	if(breath - R >= m){
		ret = min(ret, BruteForce(breath - R, exerMinute) +	 1);
	}
	else{
		ret = min(ret, BruteForce(m, exerMinute) + 1);
	}

	return ret;
}	
int main(){

	cin>>N>>m>>M>>T>>R;
	// cout<<N<<" "<<m<<" "<<M<<" "<<T<<" "<<R<<endl;
	memset(cache, -1, sizeof(cache));
	int ret = BruteForce(m , 0);
	if(ret >= 0x3f3f3f3f) ret = -1;
	cout<<ret <<endl;

	return 0;
}