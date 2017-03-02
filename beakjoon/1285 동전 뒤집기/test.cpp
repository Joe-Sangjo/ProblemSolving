#include <iostream>
#include <cstdlib>
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
	srand(time(NULL));
		
	int numofT=1000;
	int temp;
	int po;
	int RorC;
	for(int i=0;i<10000000;i++){
		RorC = rand()%2;
		if(RorC==0){
			po = rand()%size;
			for(int k=0;k<size;k++){
				a[po][k] = !a[po][k];
			}
		}
		else{
			po = rand()%size;
			for(int k=0;k<size;k++){
				a[k][po]=!a[k][po];
			}
		}
		temp =0;
		for(int p=0;p<size;p++){
			for(int q=0;q<size;q++){
				if(a[p][q] == 0){
					temp++;
				}
			}
		}
		if(temp<numofT){
			numofT = temp;
		}
	}

	cout<<endl<<endl<<numofT<<endl;
}
