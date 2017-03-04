#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

int main(){

	deque<int> dq;

	for(int i = 0; i < 100; i++){
		dq.push_back(i);
	}
	dq.pop_front();
	cout<<dq[2]<<endl;

	return 0;
}