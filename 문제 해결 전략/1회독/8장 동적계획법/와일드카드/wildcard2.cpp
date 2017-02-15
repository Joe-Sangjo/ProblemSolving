#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n;
string wild;
string file[50];

vector<int> star;
vector<int> que;

bool check(int i);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin >> TC;

	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>wild>>n;
		for(int i = 0; i < n; i++)
			cin>>file[i];

		for(int i = 0; i < wild.size(); i++){
			if(wild[i] == '*')
				star.push_back(i);
			if(wild[i] == '?')
				que.push_back(i);
		}

		for(int i = 0; i < n; i++){
			if(check(i))
				cout<<file[i]<<endl;
		}

		star.empty();
		que.empty();
	}

	return 0;
}

bool check(int i){
	if()
}