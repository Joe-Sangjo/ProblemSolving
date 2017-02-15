#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int freinds[10][10];
int cnt_picnic;
int childNum, pairNum;
void makePair(int depth,vector<int> record);
int factorial(int n);
int main(){
	freopen("input.txt","r",stdin);

	setbuf(stdout, NULL);
	int T;
	cin>>T;

	int f1, f2;
	for(int test_case = 0; test_case < T; test_case++){
		cin>>childNum>>pairNum;
		memset(freinds, 0, 100*sizeof(int));
		cnt_picnic = 0;
		vector<int> record;
		for(int i=0;i<pairNum;i++){
			cin>>f1>>f2;
			freinds[f1][f2] = 1; freinds[f2][f1] = 1;
		}
		makePair(1,record);
		cout<<cnt_picnic/(pow(2,childNum/2)*factorial(childNum/2))<<endl;
	}
	return 0;
}
void makePair(int depth,vector<int> record){
	if(depth == childNum/2+1){
		cnt_picnic++;
		return;
	}
	else{
		for(int i=0;i<childNum;i++){
			vector<int>::iterator it_i = find(record.begin(), record.end(), i);
			if(it_i==record.end()){	
				for(int j=0;j<childNum;j++){
					vector<int>::iterator it_j = find(record.begin(), record.end(), j);
					if((i!=j) && (it_j == record.end()) && (freinds[i][j]==1)){
						record.push_back(i);
						record.push_back(j);
						makePair(depth+1,record);
						record.pop_back();
						record.pop_back();
					}
				}
			}
		}
	}

}
int factorial(int n){
	int f = 1;
	while(n>1){
		f *= n--;
	}
	return f;
}