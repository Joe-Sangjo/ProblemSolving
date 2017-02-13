#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int k;
string data[20];
string global;
int re(int now, int used);
int getOverlap(string a, string b);
int dp[18][1<<15];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	int TC;
	cin>>TC;
	for(int test_case = 0; test_case < TC; test_case++){
		cin>>k;
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < k; i++){
			cin>>data[i];
			// cout<<data[i]<<" ";
		}
		// cout<<endl;
		int ret = 987654321;
		for(int i = 0; i < k ; i++){
			ret = min(ret, re(i,0)); //시작을 여러개에서 하여서 그 것들 중 가장 작은 합쳐진 문자열 길이를 반환
		}
		cout<<ret<<endl;
	}
	return 0;
}
int re(int now, int used){
	if(used == (1<<k) - 1) return 0; //모두 사용하였으면,
	int& ret = dp[now][used]; //메모이제이션
	if(ret != -1) return ret;
	ret = 987654321; //min 값이므로 infinite로 초기화
	for(int i = 0; i < k; i++){
		if(used & 1<<i){ //i가 사용되지 않았으면,
			ret = min(ret, re(i, used + 1<<i) + getOverlap(data[now],data[i])); //사용했다는 표시와 함께, now와 i의 겹칩을 더해줌.
		}
	}
	return ret;
}
int getOverlap(string a, string b){
	int kk = 0;
	for(int i = 0; i <a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			if(a[i] == b[j]){ //같으면, 
				int ii = i, jj = j;
				int k = 0;
				while(a[ii] == b[jj]){
					k++; //얼마나 겹치는지 확인
				}
				kk = max(kk, k); //가장 많이 겹치는 것을 반환
			}
		}
	}
	return a.size() + b.size() - kk;
}