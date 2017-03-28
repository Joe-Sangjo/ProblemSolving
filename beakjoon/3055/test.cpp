#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){


	vector<int> a;
	a.push_back(2); a.push_back(1);
	sort(a.begin(), a.end());
	cout<<a[0]<<" "<<a[1]<<endl;
	return 0;
}