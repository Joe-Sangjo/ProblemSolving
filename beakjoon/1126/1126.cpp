#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> height;
int main(){

	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i = 0; i < n; i++){
		int temp; cin>>temp;
		height.push_back(temp);
	}

	sort(height.begin(), height.end());



	return 0;
}