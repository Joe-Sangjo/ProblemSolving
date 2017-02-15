#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string a;
string b;
int idolNum, fanNum;
bool nothug;
bool idol[40001], fan[40001];		
void hug(int start,int left,int right);

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC;
	cin>>TC;
	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>a>>b;
		idolNum = a.size(), fanNum = b.size();
		int cnt = 0;
		for(int i= 0; i < a.size(); i++){
			idol[i] = (a[i] =='F');
		}
		for(int i = 0 ; i < b.size(); i++){
			fan[i] = (b[i] == 'F');
		}
		for(int i = 0; i <= fanNum - idolNum; i++){
			nothug = true;
			hug(i,0,idolNum-1);
			if(nothug)
				cnt++;
		}
		cout<<cnt<<endl;

	}
	return 0;
}


void hug(int start,int left,int right){
	if(!nothug) return;
	
	if(left == right){
		if(!(idol[left] || fan[left+start])){
			nothug = false;
		}
		return;
	}
	int mid = (left + right) / 2;

	hug(start, left, mid);
	if(mid + 1 <=right)
		hug(start, mid+1,right);
}