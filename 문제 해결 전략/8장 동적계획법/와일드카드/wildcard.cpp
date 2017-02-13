#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string wildcard;
int n;
string filename[50];
bool checkletter(int num_file,int wild_index,int file_index);
int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;
	cin>>TC;
	for(int test_case = 0 ; test_case < TC ; test_case ++){
		cin>>wildcard>>n;
		for(int i = 0; i < n; i++){
			cin>>filename[i];
		}
		
		for(int i = 0; i < n ; i++){
			if(checkletter(i,0,0))
				cout<<filename[i]<<endl;
		}


	}

	return 0;
}

bool checkletter(int num_file, int wild_index,int file_index){
	if(wild_index > wildcard.size() && file_index > filename[num_file].size())
		return true;
	else if( wild_index > wildcard.size() && !(file_index > filename[num_file].size()))
		return false;
	else if( !(wild_index > wildcard.size()) && file_index > filename[num_file].size())
		return false;

	bool ret;

	if(wildcard[wild_index] == '?'){
		ret = checkletter(num_file, wild_index+1, file_index+1);
	}
	else if(wildcard[wild_index] == '*'){
		if(wildcard[++wild_index] == '\0'){
			return true;
		}
		else{
			// cout<<wildcard[wild_index]<<"  "<<filename[num_file][file_index]<<endl;;
			while(wildcard[wild_index] != filename[num_file][file_index]){
				file_index++;
				if(file_index > filename[num_file].size())
					return false;
			}
			ret = checkletter(num_file, wild_index, file_index);
		}
	}
	else{
		if(wildcard[wild_index] == filename[num_file][file_index])
			ret = checkletter(num_file, wild_index+1, file_index+1);
		else
			return false;
	}

	return ret;
}