#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int n;
int h[51];
int cache[51][500010];
const int NEGINF = -0x3f3f3f3f;

int solve(int now, int dif){
	if(now == n) return dif == 0 ? 0 : NEGINF;

	int& ret = cache[now][abs(dif)];

	if(ret != -1) return ret;

	ret = solve(now + 1, dif);
	ret = max(ret, solve(now + 1, dif + h[now]) + h[now]);
	ret = max(ret, solve(now + 1, dif - h[now]) + h[now]);
	return ret;
}

int main(){
	freopen("input.txt","r",stdin);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>h[i];


	memset(cache, -1, sizeof(cache));

	int ret = solve(0,0);

	if(ret <= 0) cout<<-1;
	else cout<< ret/2;
	return 0;
}