#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const double PI = 2.0 * acos(0);
const int INF = 987654321;
int n;
double y[101], x[101], r[101];
// double begin[101], end[101];
pair<double, double> range[101];
// int solveCircular();
int solveLinear(double be, double en);
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n;
		double theta, bbb,eee;
		for(int i = 0 ; i < n; i++){
			cin>>y[i]>>x[i]>>r[i];
			theta = fmod(2*PI + atan2(y[i], x[i]), 2* PI);
			bbb= theta - 2.0 * asin(r[i] / 2.0 / 8.0);
			eee = theta + 2.0 * asin(r[i] / 2.0 / 8.0);
			range[i] = make_pair(bbb, eee);
			// cout<<range[i].first<<"  "<<range[i].second<<endl;
		}
		sort(range, range + n);
		// for(int i = 0; i < n; i++){
		// 	cout<<range[i].first<<" "<<range[i].second<<endl;
		// }
		// cout<<endl;
		int ret = INF;
		for(int i = 0 ; i < n ;i++)
			if(range[i].first <= 0 || range[i].second >= 2 *PI){

				double be = fmod(range[i].second, 2*PI);
				double en = fmod(range[i].first + 2*PI, 2*PI);

				ret = min(ret , 1 + solveLinear(be, en));

			}
		if(ret >= INF)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<ret<<endl;

	}



	return 0;
}


int solveLinear(double be, double en){
	int used = 0, idx = 0;

	while(be < en){
		double maxCover = -1;
		while(idx < n && range[idx].first <= be){
			maxCover = max(maxCover, range[idx].second);
			idx++;
		}

		if(maxCover <= be) return INF;

		be = maxCover;
		used++;
	}
	return used;
}