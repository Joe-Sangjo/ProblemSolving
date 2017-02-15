#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const string im = "IMPOSSIBLE";


int D, N, M;


vector<int> nm;
ll result;

void bfs(){

	queue<ll> q;

	q.push(0);

	while(!q.empty()){

		ll here = q.front();
		q.pop();

		for(int i = 0; i < nm.size(); i++){
			ll there = here * 10 + nm[i];
			if(there >= N + M && there % N == M){
				result = there;
				return;
			}
			q.push(there);
		}
	}

}
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);

	while(TC--){
		scanf("%d %d %d", &D, &N, &M);
		if(D == 0){
			cout<<im<<'\n';
			continue;
		}
		nm.clear();
		while(D != 0){
			nm.push_back(D%10);
			D /= 10;
		}
		sort(nm.begin(), nm.end());
		bfs();
		printf("%lld\n", result);


	}

	return 0;
}