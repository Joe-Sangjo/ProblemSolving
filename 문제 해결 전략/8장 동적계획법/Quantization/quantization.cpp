#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 987654321

int n,s;
int num[100];
int error[100][100];
int cache[11][100];
void storeError(int start, int end);
int getSumError(int dept,int start);
int main(){
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n>>s;
		for(int i = 0 ; i < n; i++){
			cin>>num[i];
		}
		memset(error, -1, sizeof(error));
		memset(cache, -1, sizeof(cache));
		sort(num, num+n);
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n ; j++){
				storeError(i,j);
			}
		}
		
		
		
		cout<<getSumError(1,0)<<endl;
	}
	return 0;
}

void storeError(int start, int end){
	double sumError = 0;

	for(int i = start; i <=end; i++)
		sumError += num[i];

	sumError /= (end-start +1);
	
	double points = sumError - (int)sumError;
	if(points >= 0.5){
		// sumError +=1;
	}
	error[start][end] = sumError;
}

int getSumError(int dept,int start){
	
	int& ret = cache[dept][start];

	if(dept == s) return ret = error[start][n-1];
	
	if(ret != -1) return ret;
	
	ret = INF;
	
	for(int end = start+1; end <= n-(s-dept) ; end++){
		ret = min(ret, getSumError(dept + 1, end+1) + error[start][end]);
		
	
	}
	
	return ret;

}