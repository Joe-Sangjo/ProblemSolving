#include <iostream>
#include <cstring>

using namespace std;



int main(){

	string a = "I am Sangjo";
	cout<<a<<endl;

	cout<<a.substr(0,8)<<endl;
	string b = "I am San";
	cout<<(a.substr(0,8) == b)<<endl;






	return 0;
}