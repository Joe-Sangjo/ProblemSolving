#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int dx[8] = {-1, -1, -1,  1, 1, 1,  0, 0};
const int dy[8] = {-1,  0,  1, -1, 0, 1, -1, 1};
string array[5];
int check_index;
bool hasword(int y, int x, const string& word);
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	cin>>T;
	int checkNum;
	string check_word[10];
	int check;
	for(int t=1;t<=T;t++){
         for(int i=0;i<5;i++){
        		cin>>array[i];
         }
         cin>>checkNum;
         for(int i=0;i<checkNum;i++){
         	cin>>check_word[i];
         }
        	for(int i=0;i<checkNum;i++){
        		check = 0;
        		for(int j=0;j<5;j++){
        			for(int k=0;k<5;k++){
        				if(check_word[i][0] == array[j][k]){
        					if(hasword(k,j,check_word[i])){
        						check = 1;
        						goto finish;
        					}
        				}
        			}
        		}
        		finish:
			if(check){
				cout<<check_word[i]<<" YES"<<endl;
			}
			else{
				cout<<check_word[i]<<" NO"<<endl;
			}
        	}
	}
	return 0;
}

bool hasword(int y, int x, const string& word){
	if(word.size()==0){
		return true;
	}
	if(array[x][y]!=word[0]){
		return false;
	}
	for(int direction = 0; direction < 8; direction++){
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if(nextX < 0 || nextY < 0 || nextX > 4 || nextY > 4){
			continue;
		}
		else{
			if(hasword(nextY,nextX,word.substr(1))){
				return true;
			}
		}
	}
	return false;
}