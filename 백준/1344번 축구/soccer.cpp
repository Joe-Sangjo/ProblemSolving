#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double a,b;
bool isPrime(int n);
double match(int score_a, int score_b, int time);
double cache[20][20][20];
int main(){
	freopen("input.txt","r",stdin);
	cin>>a>>b;
	a/=100; b/=100;
	memset(cache, -1, sizeof(cache));
	// cout<<(cache[0][0][0] == 1)<<endl;
	printf("%.12f\n",match(0,0,0) );
	return 0;
}

double match(int score_a, int score_b, int time){
	
	if(time == 18)	return (isPrime(score_a) || isPrime(score_b));

	double& ret = cache[score_a][score_b][time];

	if(ret > -0.5) return ret;
	
	
	ret = 0;

	ret += a*(1-b)*match(score_a + 1, score_b, time + 1);
	ret += (1-a)*b*match(score_a, score_b + 1, time + 1);
	ret += a*b*match(score_a + 1, score_b + 1, time + 1);
	ret += (1-a)*(1-b)*match(score_a, score_b, time + 1);
	return ret;
}

bool isPrime(int n){
	int prime[9] = {2,3,5,7,11,13,17,19,23};

	for(int i = 0 ; i < 9; i++){
		if(n == prime[i]){
			return true;
		}
	}
	return false;
}
