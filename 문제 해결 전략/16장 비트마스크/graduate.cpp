#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, K, M, L;
int pre[13], open[11];
int R[13], C[11];
int dp[11][1<<12];
int graduate(int sem, int sub);

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;
	while(TC--){
		cin>>N>>K>>M>>L;
		memset(pre, 0, sizeof(pre));
		memset(open,0, sizeof(open));
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < N; i++){
			cin>>R[i];
			for(int j = 0; j < R[i]; j++){
				int buf;
				cin>>buf;
				pre[i] |= (1<<buf); 
			}
			// cout<<pre[i]<<" ";
		}
		// cout<<endl;
		for(int i = 0; i < M; i++){
			cin>>C[i];
			for(int j = 0; j < C[i]; j++){
				int buf;
				cin>>buf;
				open[i] |= (1<<buf); 
			}
			// cout<<open[i]<<" ";
		}
		// cout<<endl<<endl;
		int ret = INF;
		// cout<<TC<<endl;
		for(int subject = open[0]; subject; subject = ((subject - 1) & open[0])){
			if(__builtin_popcount(subject) > L)	continue;

			int presubject = 0;
			for(int i = 0; i < N; i++){
				if(subject & (1<<i)){
					presubject |= pre[i];
				}
			}
			if(presubject == 0){
				// cout<<subject<<" ";
				ret = min(ret, graduate(0, subject));
			}
		}
		ret = min(ret, graduate(0, 0));
		// cout<<endl<<endl;

		if(ret >= INF){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			cout<<ret<<endl;
		}
		// cout<<endl<<endl;
	}

	return 0;
}
int graduate(int sem, int sub){
	// cout<<sem<<" "<<sub<<" "<<__builtin_popcount(sub)<<endl;
	if(sem >= M) return INF;


	if(__builtin_popcount(sub) >= K)	return sem;

	
	int& ret = dp[sem][sub];

	if(ret != -1) return ret;

	ret = INF;

	for(int subject = open[sem + 1]; subject; subject = ((subject - 1) & open[sem + 1])){
		
		if(__builtin_popcount(subject) > L)	continue;


		bool check = true;

		for(int i = 0; i < N; i++){
			if((((sub & (1<<i)) > 0) && ((subject & (1<<i)) > 0) )){
				check = false;
				break;
			}
		}
		if(!check)	continue;

		int presubject = 0;
		for(int i = 0; i < N; i++){
			if(subject & (1<<i)){
				presubject |= pre[i];
			}
		}

		// if(sem == 0 && sub == 9) cout<<"subject : "<<subject<< "  presubject : "<<presubject<<endl;
		for(int i = 0; i < N; i++){
			if((presubject & (1<<i)) > 0 && (sub & (1<<i)) == 0){
				check = false;
				break;
			}
		}
		if(!check)	continue;

		// if(sem == 0 && sub == 9) cout<<subject<<"     ";
		ret = min(ret, graduate(sem + 1, sub | subject));
		
		// ret = min(ret, graduate(sem + 1, subject));
	}
	ret = min(ret, graduate(sem + 1, sub));
	return ret;

}