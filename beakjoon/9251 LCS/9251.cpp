#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cache[1001][1001];
string a, b;

int main(){
	freopen("input.txt","r",stdin);

	cin>>a>>b;
	memset(cache, 0, sizeof(cache));

	for(int i = 1; i <= a.length(); i++){

		for(int j = 1; j <= b.length(); j++){
			if(a[i-1] == b[j-1]){
				cache[i][j] = cache[i-1][j-1] + 1;
			}
			else{
				cache[i][j] = max(cache[i][j-1],cache[i-1][j]);
			}
		}

	}
	cout<<cache[a.length()][b.length()]<<endl;

	
	return 0;
}