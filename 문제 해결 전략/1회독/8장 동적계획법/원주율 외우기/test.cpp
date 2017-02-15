#include <iostream>

using namespace std;

int retvalue(string a){
	bool check = true;

	for(int i = 0 ; i < a.size()-1 ; i++){
		if(a[i] != a[i+1]){
			check = false;
			break;
		}
	}
	if(check) return 1;

	check = true;

	for(int i = 0; i < a.size() -1 ; i++){
		if(a[i] + 1 != a[i+1]){
			check = false;
			break;
		}
	}

	if(check) return 2;

	check = true;

	for(int i = 0; i < a.size() -1 ; i++){
		if(a[i] -1 != a[i+1]){
			check = false;
			break;
		}
	}

	if(check) return 2;

	check = true;

	for(int i = 2 ; i < a.size(); i+=2){
		if(a[0]!=a[i]){
			check = false;
			break;
		}
	}
	for(int i = 3; i < a.size(); i+=2){
		if(a[1]!=a[i]){
			check = false;
			break;
		}
	}

	if(check) return 4;

	check = true;
	for(int i = 1; i < a.size()-1 ; i++){
		if(a[0]-a[1] != a[i]-a[i+1]){
			check = false;
			break;
		}
	}

	if(check) return 5;

	return 10;
}
int main(){



	string a = "121asdfasdfasdf";

	// cout<<retvalue(a)<<endl;
	cout<<a.substr(10,8)<<endl;


	return 0;
}