#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


string order;
string bridge[2];
int cache[2][101][21];
int cross(int y, int x, int letter);
int main(){
	freopen("input.txt","r",stdin);
	cin>>order>>bridge[0]>>bridge[1];
	memset(cache, -1, sizeof(cache));

	int ret = 0;
	for(int i = 0; i < bridge[0].size(); i++){
		if(bridge[0][i] == order[0])
			ret += cross(0,i,0);
	}
	for(int i = 0; i < bridge[1].size(); i++){
		if(bridge[1][i] == order[0])
			ret += cross(1,i,0);

	}
	cout<<ret<<endl;

	return 0;
}

int cross(int y, int x, int letter){
	
	if(letter == order.size() - 1) return 1;

	int& ret = cache[y][x][letter];

	if(ret != -1) return ret;

	ret = 0;

	if(y == 0){
		for(int next = x + 1; next < bridge[0].size(); next++){
			if(bridge[1][next] == order[letter + 1]){
				ret += cross(1, next, letter + 1);
			}
		}
	}
	else{
		for(int next = x + 1; next < bridge[0].size(); next++){
			if(bridge[0][next] == order[letter + 1])
				ret += cross(0, next, letter + 1);
		}
	}
	return ret;
}