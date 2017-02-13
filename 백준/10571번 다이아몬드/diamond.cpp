#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int N;
double infor[300][2];
int cache[300][300];
int selectDiamond(int idx, int num);
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>N;
		memset(cache, -1, sizeof(cache));
		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < 2; j++){
				cin>>infor[i][j];
			}
		}
		int ret = 0;
		for(int i = 0; i < N; i++){
			ret = max(ret, selectDiamond(0, i) + 1);
		}
		cout<<ret<<endl;
	}
	return 0;
}

int selectDiamond(int idx, int num){
	if(idx == N -1) return 0;

	int& ret = cache[idx][num];

	if(ret != -1) return ret;

	ret = 0;

	for(int i = 0 ; i < N; i++){
		if((idx != i) && ((infor[i][0] >= infor[num][0]) && (infor[i][1] < infor[num][1]))){
			ret = max(ret, selectDiamond(idx + 1, i) + 1);
		}
		else if((idx != i) && ((infor[i][0] > infor[num][0]) && (infor[i][1] <= infor[num][1]))){
			ret = max(ret, selectDiamond(idx + 1, i) + 1);
		}
	}
	return ret;
}