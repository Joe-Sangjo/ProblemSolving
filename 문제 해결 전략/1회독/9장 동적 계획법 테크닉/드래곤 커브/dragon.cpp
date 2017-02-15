#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, p, l;
string dragon[51];
void making(int n);
int main(){
	freopen("input.txt","r",stdin);
	int TC; cin>>TC;
	dragon[0] = "FX";
	// dragon[1] = "FX+YF";
	// dragon[2] = "FX+YF+FX-YF";
	// making(1);
	// making(2);
	// cout<<dragon[1]<<endl;
	// cout<<dragon[2]<<endl;
	for(int i = 1; i < 10; i++){
		making(i);
		cout<<dragon[i - 1]<<endl<<endl;
	}



	// for(int test_case = 0; test_case < TC ;test_case ++){
	// 	cin>>n>>p>>l;

	// 	// for(int i = 1; i <= n; i++){
	// 		making(i);
	// 	// }

	// 	// for(int i = p - 1; i < p + l - 1 ; i++){
	// 	// 	cout<<dragon[n][i];
	// 	// }
	// 	// cout<<endl;
	// }

	return 0;
}

void making(int n){
	if(dragon[n] != "\0") return;
	
	string d = dragon[n-1];

	for(int i = 0; i < d.size(); i++){
		if(d[i] == 'X'){
			if(i<=1){
				d.insert(i+1,"+YF");
			}
			else{
				if(d[i-2]=='-'){
					d.insert(i+1,"-YF");
				}
				else{
					d.insert(i+1,"+YF");
				}
			}
			i += 3;
		}
		else if(d[i] == 'Y'){
			if(d[i-1] =='-'){
				d.insert(i,"FX+");
			}
			else{
				d.insert(i,"FX-");
			}
			i+=3;
		}
	}
	dragon[n] = d;
}