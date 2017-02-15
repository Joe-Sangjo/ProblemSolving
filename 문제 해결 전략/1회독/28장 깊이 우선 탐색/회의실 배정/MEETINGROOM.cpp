#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const string IM = "IMPOSSIBLE";
const string PO = "POSSIBLE";

int N;
int a[101], b[101], c[101], d[101];
int dp[101][2];

int meeting(int idx, int mw);
void reconstruct(int idx, int mw, vector<int>& order);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		}
		memset(dp, -1, sizeof(dp));

		int ret, ret1, ret2;

		ret1 = meeting(0, 0); ret2 = meeting(0, 1);

		ret = ret1 || ret2;


		if(ret){
			cout<<PO<<endl;
			vector<int> order;
			if(ret1){
				reconstruct(0,0,order);

			}
			else{
				reconstruct(0, 1, order);
			}
			for(int i = 0; i < order.size(); i++){
				if(order[i]){
					printf("%d %d\n", a[i], b[i] );
				}
				else{
					printf("%d %d\n", c[i], d[i]);
				}
			}
		} 
		else{
			cout<<IM<<endl;
		}

	}
	return 0;
}

int meeting(int idx, int mw){

	if(idx == N - 1)	return 1;

	int& ret = dp[idx][mw];

	if(ret != -1) return ret;

	ret = 0;
	if(mw == 0){
		if(b[idx] <= a[idx + 1])
			ret = ret || meeting(idx + 1, 0);
		if(b[idx] <= c[idx + 1])
			ret = ret || meeting(idx + 1, 1);
	}
	else{
		if(d[idx] <= a[idx + 1])
			ret = ret || meeting(idx + 1, 0);
		if(d[idx] <= c[idx + 1])
			ret = ret || meeting(idx + 1, 1);
	}
	return ret;
}

void reconstruct(int idx, int mw, vector<int>& order){
	order.push_back(mw);


	if(idx == N - 1) return;

	if(mw == 0){
		if(b[idx] <= a[idx + 1]){
			reconstruct(idx + 1, 0, order);
		}
		else if(b[idx] <= c[idx + 1]){
			reconstruct(idx + 1, 1, order);
		}
	}
	else{
		if(d[idx] <= a[idx + 1]){
			reconstruct(idx + 1, 0, order);
		}
		else if(d[idx] <= c[idx + 1]){
			reconstruct(idx + 1, 1, order);
		}
	}
}