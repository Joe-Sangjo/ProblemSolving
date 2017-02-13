#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int microwave[10001];
int eating[10001];
int main(){

	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	for(int test_case = 0 ; test_case < TC ; test_case++){
		// vector<pair<int, int> > 
		cin>>N;
		for(int i = 0 ; i < N; i++){
			cin>>microwave[i];
		}
		for(int i = 0; i < N ; i++){
			cin>>eating[i];
		}

		vector<pair<int, int> > data;
		for(int i = 0 ; i < N ; i++)
			data.push_back(make_pair(-eating[i],microwave[i]));

		
		sort(data.begin(), data.end());
		for(int i = 0; i < N ; i++){
			cout<<data[i].first<<" "<<data[i].second<<endl;
		}
		for(int i = 0; i < N; i++){
			data[i].first *=-1;
		}
		for(int i = 0; i < N ; i++){
			cout<<data[i].first<<" "<<data[i].second<<endl;
		}
		
		int pre_micro = data[N-1].second;
		int finish_time = 0;

		for(int i = N - 1 ; i >=0; i--){
			// cout<<pre_micro<<" ";
			finish_time = max(finish_time, pre_micro + data[i].first);
			pre_micro += data[i-1].second;

			
		}
		// cout<<endl<<endl;
		cout<<finish_time<<endl;
	}


	return 0;
		
}