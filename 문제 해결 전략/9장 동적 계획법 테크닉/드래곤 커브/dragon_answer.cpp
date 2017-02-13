#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

int n, p, l;
const int MAX = 1000000000 + 1;
int length[51];
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";


void precalc();
char expand(const string& dragonCurve, int generations, int skip);
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	precalc();
	// for(int i = 0 ; i < 50; i++){
	// 	cout<<length[i]<<" ";
	// }
	// cout<<endl;
	for(int test_case = 0; test_case < TC ;test_case++){
		cin>>n>>p>>l;
		for(int i = p - 1; i < p + l - 1; i++){
			cout<<expand("FX", n, i);
		}
		cout<<endl;
	}


	return 0;
}

void precalc(){
	length[0] = 1;
	for(int i = 1; i <= 50; i++){
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	}
}

char expand(const string& dragonCurve, int generations, int skip){
	if(generations == 0){
		// assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}
	for(int i = 0; i < dragonCurve.size(); i++){
		if(dragonCurve[i] == 'X' || dragonCurve[i] =='Y'){
			if(skip >= length[generations])
				skip -= length[generations];
			else if(dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else
				return expand(EXPAND_Y, generations - 1, skip);
		}

		else if(skip > 0)
			skip--;
		else
			return dragonCurve[i];
	}
	return '#';
}