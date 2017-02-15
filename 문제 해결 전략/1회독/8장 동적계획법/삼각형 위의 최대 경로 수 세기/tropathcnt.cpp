#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int triangle[101][101];
int cache[101][101];
int cnt_path[101][101];
int path(int i, int j);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j <=i; j++){
				cin>>triangle[i][j];
				// cout<<triangle[i][j];
			}
			// cout<<endl;
		}

		for(int i = 0 ; i < n ; i++)
			cnt_path[n-1][i] = 1;

		memset(cache, -1, sizeof(cache));
		path(0,0);
		cout<<cnt_path[0][0]<<endl;

	}


	return 0;
}

int path(int i, int j){

	if(i == n-1) return triangle[i][j];

	int& ret = cache[i][j];
	if(ret != -1) return ret;

	int temp1 = path(i+1,j);
	int temp2 = path(i+1, j+1);
	ret = triangle[i][j] + max(temp1, temp2);

	if(temp1 > temp2)
		cnt_path[i][j] = cnt_path[i+1][j];
	else if( temp2 > temp1)
		cnt_path[i][j] = cnt_path[i+1][j+1];
	else
		cnt_path[i][j] = cnt_path[i+1][j] + cnt_path[i+1][j+1];
	return ret;
}