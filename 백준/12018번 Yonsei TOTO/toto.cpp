#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n, m;
int p[101], l[101];
int mileage[101][101];
int min_possible[101];
int main(){

	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i = 0 ; i < n ; i ++){
		cin>>p[i]>>l[i];
		for(int j = 0; j < p[i]; j++){
			cin>>mileage[i][j];
		}
		sort(mileage[i], mileage[i] + p[i]);
		if(p[i] >= l[i]){
			min_possible[i] = mileage[i][p[i] - l[i]];;
		}
		else{
			min_possible[i] = 1;
		}
	}
	// for(int i = 0; i < n; i++){
	// 	cout<<min_possible[i]<<" ";
	// }
	// cout<<endl<<endl;

	sort(min_possible, min_possible +n);
	int cnt = 0;
	int result = 0;

	for(int i = 0; i < n ; i++){
		result += min_possible[i];
		if(result > m) break;
		else	cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}