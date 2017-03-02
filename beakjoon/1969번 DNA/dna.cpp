#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string dna[1001];
string Hamming;
int main(){
	freopen("input.txt","r",stdin);
	cin>>N>>M;
	for(int i = 0 ; i < N; i++){
		cin>>dna[i];
	}

	vector<pair<int, char> > data;
	int a, c, g, t;
	
	for(int j = 0 ; j < M; j++){
		a = c = g = t = 0;
		data.clear();
		char st[4];
		for(int i = 0 ; i < N; i++){
			if(dna[i][j] == 'A') a++;
			else if(dna[i][j] == 'C') c++;
			else if(dna[i][j] == 'G') g++;
			else t++;
		}
		data.push_back(make_pair(t, 'T'));
		data.push_back(make_pair(g, 'G'));
		data.push_back(make_pair(c, 'C'));
		data.push_back(make_pair(a, 'A'));

		sort(data.begin(), data.end());
		if(data[3].first > data[2].first){
			Hamming+=data[3].second;
		}
		else{
			if(data[2].first > data[1].first){
				st[0] = data[3].second;
				st[1] = data[2].second;
				sort(st, st + 2);
				Hamming += st[0];
			}
			else{
				if(data[1].first > data[0].first){
					st[0] = data[3].second;
					st[1] = data[2].second;
					st[2] = data[1].second;
					sort(st, st + 3);
					Hamming +=st[0];
				}
				else{
					st[0] = data[3].second;
					st[1] = data[2].second;
					st[2] = data[1].second;
					st[3] = data[0].second;
					sort(st, st + 4);
					Hamming += st[0];
				}
			}
		}
	}

	cout<<Hamming<<endl;
	return 0;
}