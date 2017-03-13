#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	char a = 'A';
	cout<<char((int)a + 1)<<endl;

	char b = '1';
	cout<<char((int)b + 1)<<endl;
	string k = a+b;
	return 0;
}