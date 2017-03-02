#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int tet[125];

void setting();

const int INF = 999999999;
int cache[300001];
int N;
int maketet(int n);
int main(){
	memset(cache, -1, sizeof(cache));
	// cin>>N;
	N = 300000-1;
	setting();
	

	cout<<maketet(N)<<endl;


	return 0;
}
int maketet(int n){
	// cout<<n<<endl;
	if(n == 0) return 0;

	int& ret = cache[n];

	if(ret != -1) return ret;

	ret = INF;

	for(int i = 124; i >= 0; i--){
		if(tet[i] <=n)
			ret = min(ret, maketet(n-tet[i]) + 1);
	}
	return ret;
}

void setting(){
	tet[0] = 1;
	tet[1] = 4;
	int tri[125];
	tri[0] = 1;
	tri[1] = 3;

	for(int i = 2; i< 125; i++){
		tri[i] = tri[i-1] + i+1;
		tet[i] = tet[i-1] + tri[i];
	}
}