#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int N;
bool visited[101];
int number[101];


int dfs(int here, int first){

	visited[here] = true;

	int ret = -0x3f3f3f3f;

	int there = number[here];

	//사이클이 된 경우
	if(there == first){
		return 1;
	}

	if(!visited[there]){
		ret = dfs(there, first) + 1;
	}

	//사이클이 안된 경우 방문했던 기록을 지운다.
	if(ret < 0){
		visited[here] = false;
	}

	return ret;
}

int main(){
	freopen("input.txt","r",stdin);

	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>number[i];
	}
	memset(visited, false, sizeof(visited));

	int ret = 0;
	for(int i = 1; i <= N; i++){
		int temp = 0;
		if(!visited[i])
			temp = dfs(i,i);
		if(temp > 0){
			ret += temp;
		}
	}

	cout<<ret<<endl;
	for(int i = 1; i <= N; i++){
		if(visited[i])
			cout<<i<<endl;
	}
	return 0;
}