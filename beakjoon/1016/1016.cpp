#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
typedef long long int ll;
using namespace std;
ll MIN, MAX;
const int size = 1100000;
//true인 것의 index는 소수
bool prime[size];
vector<ll> p;
int main(){

	// scanf("%lld %lld", &MIN, &MAX);
	MIN = 97, MAX = 10000;
	memset(prime, true, sizeof(prime));

	prime[0] = prime[1] = false;

	for(int i = 2; i * i < size ; i++){
		for(int j = i * i; j < size ; j += i){
			prime[j] = false;
		}
	}



	for(ll i = 2; i < size; i++){
		if(prime[i]){
			p.push_back(i);
			// printf("%lld\n",i );
		}
	}
	memset(prime, true, sizeof(prime));


	for(int i = 0; i < p.size() ; i++){
		ll n = p[i] * p[i];
		for(ll i = (MIN%n) ? (MIN / n + 1)*n : MIN ; i <= MAX; i += n){
			prime[i - MIN] = false;
		}
	}


	ll ret = 0;
	for(int i = 0; i < MAX - MIN + 1; i++){
		ret += prime[i];
	}
	printf("%lld\n", ret);

	return 0;
}