#include <iostream>
#include <cstdio>
using namespace std;
int a, b, c, N, K;
int main(){
	freopen("input.txt","r",stdin);
	int TC;
	cin>>TC;
	for(int test_case = 1; test_case <= TC; test_case++){
		cin>>a>>b>>c;
		string ret ="";
		while(c--){
			cin>>N>>K;
		
			int temp = (N - 1) % (a * K + b);
			int temp2 = (N - b) % (a * K + b);
			int temp3 = (N - a - b) % (b * K + a);
			int temp4 = (N - a - b - 1) % (b * K + a);
			if(temp2 <= a * K && temp >= a){
				ret+= "a";
			}
			else if(temp4 <= b * K && temp3 >= 0){
				ret += "b";
			}
			else{
				ret += "a";
			}
		}
		cout<<"Case #"<<test_case<<endl;
		cout<<ret<<endl;
	}
	return 0;
}