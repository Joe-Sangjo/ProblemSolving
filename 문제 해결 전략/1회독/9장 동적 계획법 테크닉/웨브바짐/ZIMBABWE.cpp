#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>

typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll e;
int m, n;
deque<int> array;
int egg(int now, int used, ll num);
int cache[10][1<<14];
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>e>>m;
		n = 0;
		memset(cache, -1, sizeof(cache));
		array.clear();
		while(e != 0){
			// cout<<e % 10<<" ";
			array.push_front(e % 10);
			e /= 10;
		}
		n = array.size();
		// cout<<endl;
		// for(int i = 0; i < n; i++){
		// 	cout<<array[i]<<" ";
		// }
		// cout<<endl;
		cout<<egg(n - 1,0, 0)<<endl;
	}

	return 0;
}

int egg(int now, int used, ll num){
	cout<<now<<" "<<used<<" "<<num<<endl;
	if(now == 0){
		int a;
		for(int i = 0; i < n; i++){
			if(used & (1<<i)) continue;
			else{
				a = i;
				break;
			}
		}
		num += array[a];
		return (num < e) && (num % m == 0);
	}

	int& ret = cache[now][used];

	if(ret != -1) return ret;

	ret = 0;

	for(int i = 0; i < n; i++){
		if(used & (1<<i)) continue;

		ret += egg(now - 1, used + (1<<i) , num + array[i] * pow(10, now));
	}
	return ret;
}