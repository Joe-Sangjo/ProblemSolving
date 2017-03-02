#include <iostream>
#include <string>
using namespace std;

int main(){
	int size;
	string input;
	cin>>size;
	int a[size][size];

	for(int i=0;i<size;i++){
		cin>>input;
		for(int j=0;j<size;j++){
			a[i][j] = input[j];
		}
	}

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(a[i][j]==72){
				a[i][j]=1;
			}
			else{
				a[i][j]=0;
			}
		}
	}

	int cnt=0;	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(a[i][j]==0){
				cnt+=i+j+2;
			}
		}
	}
	cout<<cnt%size<<endl;

}