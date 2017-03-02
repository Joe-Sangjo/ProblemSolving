#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int N;
double infor[300][2];
int cache[300];
int selectDiamond(int num);
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
			ret = max(ret, selectDiamond(i));
		}
		cout<<ret<<endl;
	}
	return 0;
}
int selectDiamond(int num){
	int& ret = cache[num];

	if(ret != -1) return ret;

	ret = 1;

	for(int i = num + 1 ; i < N; i++){
		if(((infor[i][0] >= infor[num][0]) && (infor[i][1] < infor[num][1]))){
			ret = max(ret, selectDiamond(i) + 1);
		}
		else if(((infor[i][0] > infor[num][0]) && (infor[i][1] <= infor[num][1]))){
			ret = max(ret, selectDiamond(i) + 1);
		}
	}
	return ret;
}