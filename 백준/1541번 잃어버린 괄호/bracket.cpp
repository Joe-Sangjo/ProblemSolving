#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	
	int num1;
	cin>>num1;

	int result = num1;
	bool isminus = (num1 < 0);
	while(cin>>num1){
		if(!isminus){
			isminus = (num1 < 0);
		}

		if(isminus){
			if(num1 < 0){
				result += num1;
			}	
			else{
				result -= num1;
			}	
		}
		else{
			result += num1;
		}
	}
	cout<<result<<endl;


	return 0;
}