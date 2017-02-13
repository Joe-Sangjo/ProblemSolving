#include <iostream>
#include <cmath>
#include <cstring>


using namespace std;

string code;
const int MOD = 1000000;

int cache[5001];
int decode(int n);
int main(){

	// cin>>code;
	code = "25114";
	memset(cache, -1, sizeof(cache));

	cout<<decode(0)<<endl;


	return 0;
}

int decode(int n){
	if(n == code.size()) return 1;

	if(n > code.size()) return 0;
	int& ret = cache[n];

	if(ret != -1) return ret;

	if(code[n] == '0'){
		return 0;
	}
	else if(code[n] =='1'){
		ret = decode(n+1) + decode(n+2);
	}
	else if(code[n] =='2'){
		if(code[n+1] <= '6'){
			ret = decode(n+1) + decode(n+2);
		}
		else{
			ret = decode(n+1);
		}
	}
	else{
		ret = decode(n+1);
	}
	return ret % MOD; 

}