#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define min(a,b) (a < b ? a : b)
#define INF 100000000
int MIN;
vector<vector<int> > swit;
int clk[16];
int switPress[10];
void Press();
void Pressing(int switchNum, int i,int totalPress);
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	cin>>T;
	for(int i=0 ; i < 12 ; i++){
		swit.push_back(vector<int>());
	}
	swit[0].push_back(0); 	swit[0].push_back(1); 	swit[0].push_back(2);
	swit[1].push_back(3); 	swit[1].push_back(7); 	swit[1].push_back(9);	 	swit[1].push_back(11);
	swit[2].push_back(4); 	swit[2].push_back(10); 	swit[2].push_back(14); 	swit[2].push_back(15);
	swit[3].push_back(0); 	swit[3].push_back(4); 	swit[3].push_back(5); 	swit[3].push_back(6); 	swit[3].push_back(7);
	swit[4].push_back(6); 	swit[4].push_back(7); 	swit[4].push_back(8); 	swit[4].push_back(10);	swit[4].push_back(12);
	swit[5].push_back(0); 	swit[5].push_back(2); 	swit[5].push_back(14); 	swit[5].push_back(15);
	swit[6].push_back(3);		swit[6].push_back(14); 	swit[6].push_back(15);
	swit[7].push_back(4); 	swit[7].push_back(5); 	swit[7].push_back(7);		swit[7].push_back(14);	swit[7].push_back(15);
	swit[8].push_back(1); 	swit[8].push_back(2); 	swit[8].push_back(3); 	swit[8].push_back(4); 	swit[8].push_back(5);
	swit[9].push_back(3); 	swit[9].push_back(4); 	swit[9].push_back(5); 	swit[9].push_back(9); 	swit[9].push_back(13);
	for(int test_case=0; test_case<T;test_case++){
		MIN = INF;
		for(int i = 0; i < 16 ; i++){
			cin>>clk[i];
			clk[i] = (clk[i]/3)%4;
		}
		for(int i = 0; i < 10 ; i++){
			switPress[i] = 0;
		}
		Press();
		if(MIN<INF)
			cout<<MIN<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}


void Press(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < swit[0].size(); j++){
			clk[swit[0][j]]+=i;
			clk[swit[0][j]]%=4;

		}
		Pressing(1,i,i);
		for(int j = 0; j < swit[0].size(); j++){
			clk[swit[0][j]]-=i;
			if(clk[swit[0][j]] < 0)
				clk[swit[0][j]]+=4;
		}
	}
}

void Pressing(int switchNum, int i,int totalPress){
	if(totalPress > MIN) return;
	if(switchNum ==10) {
		// cout<<totalPress<<" ";
		bool check = true;
		for(int i = 0; i < 16; i++){
			if(clk[i] != 0){
				check = false;
				break;
			}
		}
		if(check){
			MIN = min(MIN,totalPress);
		}
		return;
	}

	for(int i = 0 ; i < 4; i++){
		for(int j = 0; j < swit[switchNum].size(); j++){
			clk[swit[switchNum][j]]+=i;
			clk[swit[switchNum][j]]%=4;

		}
		Pressing(switchNum+1, i,totalPress+i);
		for(int j = 0; j < swit[switchNum].size(); j++){
			clk[swit[switchNum][j]]-=i;
			if(clk[swit[switchNum][j]] < 0)
				clk[swit[switchNum][j]]+=4;
		}
	}
}