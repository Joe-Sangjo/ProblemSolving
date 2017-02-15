#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
const int INF = 5000000;
typedef long long ll;
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	scanf("%d", &TC);

	while(TC--){
		int n;	scanf("%d", &n);
		vector<pair<ll, ll > > time(n);
		for(int i = 0; i < n; i++){
			scanf("%lld %lld",  &time[i].first, &time[i].second);;
		}

		priority_queue<pair<ll, pair<ll, ll> > > pq;
		for(int i = 0; i < n; i++){
			pair<int, int> a = make_pair(-time[i].first, -time[i].second);
			pq.push(make_pair(max(a.first,a. second), a));
		}		
		int i = 0;
		while(true){
			if(i++ == INF){
				printf("%s\n","IMPOSSIBLE" );
				break;
			}
			ll fi = pq.top().second.first, se = pq.top().second.second;
			pq.pop();
			if(fi == se){
				printf("%lld\n",-fi);
				break;
			}

			for(int i = 0; i < n; i++){
				pair<int, int> a = make_pair(fi-time[i].first, se-time[i].second);
				pq.push(make_pair(max(a.first, a.second),a));
			}
		}
	}



	return 0;
}