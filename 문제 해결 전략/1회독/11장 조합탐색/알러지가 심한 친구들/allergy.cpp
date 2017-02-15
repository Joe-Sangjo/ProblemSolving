#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, m;
string friends[21];
bool canEat[21][21];
int best;
void brute_force(int prepare);
bool isSearch[1<<20];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n>>m;
		for(int i = 0 ; i < n ; i++){
			cin>>friends[i];
		}
		vector<pair<int, int> > index_number;
		vector<string> eatableFriends[21];
		int buf;
		string buf2;
		for(int i = 0; i < m; i++){
			cin>>buf;
			index_number.push_back(make_pair(-buf,i));
			for(int j = 0; j < buf; j++){
				cin>>buf2;
				eatableFriends[i].push_back(buf2);
			}
		}

		sort(index_number.begin(), index_number.end());
		memset(canEat, false, sizeof(canEat));
		memset(isSearch, false, sizeof(isSearch));
		for(int i = 0; i < index_number.size(); i++){
			for(int k = 0; k < eatableFriends[index_number[i].second].size(); k++){
				for(int p = 0; p < n; p++){
					if(eatableFriends[index_number[i].second][k] == friends[p]){
						canEat[i][p] = true;
					}
				}
			}		
		}
		best = INF;
		for(int i = 0; i < m; i++){
			brute_force(1<<i);
		}
		cout<<best<<endl;
	}

	return 0;
}

void brute_force(int prepare){
	// cout<<prepare<<endl;

	if(prepare == (1<< m) - 1){
		best = min(best, m);
		return;
	}	

	int num = 0;
	for(int i = 0 ; i < m; i++){
		if(prepare & (1<<i)){
			num++;
		}
	}

	if(num >= best) return;

	bool eatfriend[21];

	memset(eatfriend, false, sizeof(eatfriend));

	for(int y = 0; y < m; y++){
		if(prepare & (1<<y)){
			for(int x = 0; x < n; x++){
				if(canEat[y][x]){
					eatfriend[x] = true;
				}
			}
		}
	}
	bool alleat = true;
	for(int i = 0; i < n; i++){
		if(!eatfriend[i]){
			alleat = false;
		}
	}
	if(alleat){
		best = min(best, num);
		return;
	}

	for(int i = 0; i < m ; i ++){
		if(!(prepare & (1<<i)) && !isSearch[prepare | (1 << i) ]){
			isSearch[prepare | (1<<i)] = true;
			brute_force(prepare | 1<<i);
		}
	}

}