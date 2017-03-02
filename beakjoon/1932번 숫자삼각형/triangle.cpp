#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int tri(int y, int x);
int t[501][501];
int cache[501][501];
int main(){
	freopen("input.txt","r",stdin);
	cin>>n;
	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin>>t[i][j];
			// cout<<t[i][j];
		}
		// cout<<endl;
	}

	cout<<tri(0,0)<<endl;


	return 0;
}
int tri(int y, int x){
	if(y == n || x == n) return 0;

	int&ret = cache[y][x];

	if(ret != -1) return ret;

	ret = t[y][x];

	return ret += max(tri(y + 1, x), tri(y + 1, x + 1)); 

}