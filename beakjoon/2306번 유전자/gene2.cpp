#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

string gene;
bool isPairing[501];
void pairing(int now);
int main(){
	freopen("input.txt","r",stdin);
	cin>>gene;
	gene = "atgcacttagatagtcctt";
	memset(isPairing, false, sizeof(isPairing));
	for(int i = 0; i <gene.size() - 1; i++){
		if(gene[i] == 'a' || gene[i] == 'g')
			pairing(i);
	}
	int cnt = 0;
	for(int i = 0 ; i < gene.size(); i++){
		if(isPairing[i])
			cnt++;
	}
	cout<<cnt;
	cout<<endl;

	return 0;
}

void pairing(int now){
	if(isPairing[now]) return;

	for(int next = now + 1 ; next < gene.size(); next++){
		if(((gene[now] == 'a' && gene[next] == 't') ||
		(gene[now] == 'g' && gene[next] == 'c')) && !isPairing[next]){
			isPairing[now] = isPairing[next] = true;
			return;
		}
	}
	return;
}