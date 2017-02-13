#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define min(a,b) (a < b ? a : b)
#define INF 10
int MIN;
vector<vector<int> > swit;
int clk[16];
int switPress[10];
void change();
void change_clock(int switNum, int depth);
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
	for(int test_case=0; test_case<T-1;test_case++){
		MIN = INF;
		for(int i = 0; i < 16 ; i++){
			cin>>clk[i];
			clk[i] = (clk[i]/3)%4;
		}
		for(int i = 0; i < 10 ; i++){
			switPress[i] = 0;
		}
		change();
		cout<<MIN<<endl;
	}
	return 0;
}
void change(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < swit[i].size(); j++){
			clk[swit[i][j]]++;
			clk[swit[i][j]]%=4;
		}
		switPress[i]++;
		change_clock(i, 1);	
		switPress[i]--;
		for(int j = 0; j < swit[i].size(); j++){
			if(--clk[swit[i][j]]== -1){
				clk[swit[i][j]] = 3;
			}
		}
	}
}
void change_clock(int switNum, int depth){
	
	if(depth >= MIN) return;

	for(int i = 0 ; i < 10 ; i++){
		if(switPress[i] >=4){
			return;
		}
	}

	bool check = true;
	for(int i = 0; i < 16; i++){
		if(clk[i] != 0){
			check = false;
			break;
		}
	}
	if(check){
		cout<<depth<<"    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		MIN = min(depth, MIN);
		return;
	}

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < swit[i].size(); j++){
			clk[swit[i][j]]++;
			clk[swit[i][j]]%=4;
		}
		switPress[i]++;
		change_clock(i, depth + 1);
		switPress[i]--;
		for(int j = 0; j < swit[i].size(); j++){
			if(--clk[swit[i][j]]== -1){
				clk[swit[i][j]] = 3;
			}
		}
	}
}
