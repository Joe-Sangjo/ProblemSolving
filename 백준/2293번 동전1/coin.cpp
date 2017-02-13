#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
int coin[101];

int ca[10001];
int re[10001];
int main(){
	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i = 0; i < n; i ++){
		cin>>coin[i];
	}
	sort(coin, coin + n);

	re[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(j < coin[i]){
				re[j] = ca[j];
			}
			else{
				re[j] = ca[j] + re[j -coin[i]];
			}
		}
		for(int j = 1; j <= k; j++){
			ca[j] = re[j];
		}

	}
	for(int i = 0; i <=k ; i++){
		cout<<re[i]<<" ";
	}
	cout<<endl;





	return 0;
}