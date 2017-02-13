#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int *getbinary(int a[4]);
int* getdecimal(int a[32]);
int main(){
	int num;
	// cin>>num;
	num=4;
	string a[num];
	// for(int i=0;i<num;i++){
	// 	cin>>a[i];
	// }
	a[0]="194.85.160.176";
	a[1]="194.85.160.183";
	a[2]="194.85.160.178";
	a[3]="194.85.160.100";
	int array[num][4];
	for(int i=0;i<num;i++){
		for(int j=0;j<4;j++){
			array[i][j]=0;
		}
	}
	int p,q;
	for(int i=0;i<num;i++){
		q=0;
		p=0;
		while(a[i][q]!='.'){
			array[i][p]=array[i][p]*10+a[i][q]-48;
			q++;
		}
		q++;
		p++;
		while(a[i][q]!='.'){
			array[i][p]=array[i][p]*10+a[i][q]-48;
			q++;
		}
		q++;
		p++;
		while(a[i][q]!='.'){
			array[i][p]=array[i][p]*10+a[i][q]-48;
			q++;
		}
		q++;
		p++;
		while(a[i][q]!='\0'){
			array[i][p]=array[i][p]*10+a[i][q]-48;
			q++;
		}
	}
	// for(int i=0;i<num;i++){
	// 	for(int j=0;j<4;j++){
	// 		cout<<array[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int *bi[num];
	for(int i=0;i<num;i++){
		bi[i] = array[i];
	}
	for(int j=0;j<num;j++){
		bi[j] = getbinary(array[j]);
		// for(int i=31;i>=24;i--){
		// 	cout<<*(bi[j]+i);
		// }
		// cout<<endl;
		// for(int i=23;i>=16;i--){
		// 	cout<<*(bi[j]+i);
		// }
		// cout<<endl;
		// for(int i=15;i>=8;i--){
		// 	cout<<*(bi[j]+i);
		// }
		// cout<<endl;
		// for(int i=7;i>=0;i--){
		// 	cout<<*(bi[j]+i);
		// }
		// cout<<endl<<endl;
	}

	int *kk;
	kk=bi[0];
	int fdsa=0;
	for(int i=31;i>=0;i--){
		for(int j=1;j<num;j++){
			if(*(kk+i)==bi[j][i]){
				continue;
			}
			else{
				if(i>fdsa){
					fdsa = i;
				}
				*(kk+i)=0;
				break;
			}
		}
		// cout<<*(kk+i);
		// if((i==24) ||(i==16)||(i==8)){
		// 	cout<<endl;
		// }
	}
	for(int i=fdsa ;i>=0;i--){
		*(kk+i)=0;
	}
	// cout<<endl<<endl;
	int *IP_return;
	IP_return = getdecimal(kk);
	cout<<*(IP_return)<<"."<<*(IP_return+1)<<"."<<*(IP_return+2)<<"."<<*(IP_return+3);
	cout<<endl;
	kk=bi[0];
	int *kkk=new int[32];
	for(int i=0;i<32;i++){
		*(kkk+i) = 1;
	}
	int *Mask_return;
	// Mask_return = getdecimal(kkk);
	// cout<<*(Mask_return)<<"."<<*(Mask_return+1)<<"."<<*(Mask_return+2)<<"."<<*(Mask_return+3)<<endl;
	int asdf=0;
	for(int i=31;i>=0;i--){
		for(int j=1;j<num;j++){
			if(*(kk+i)==bi[j][i]){
				continue;
			}
			else{
				if(i>asdf){
					asdf=i;
				}
			}
		}
	}
	for(int i=0;i<=asdf;i++){
		*(kkk+i) = 0;
	}
	Mask_return = getdecimal(kkk);
	cout<<*(Mask_return)<<"."<<*(Mask_return+1)<<"."<<*(Mask_return+2)<<"."<<*(Mask_return+3)<<endl;



	for(int i=0;i<num;i++){
		delete bi[i];
	}
}
int *getbinary(int a[4]){
	int *b= new int[32];
	for(int i=0;i<4;i++){
		for(int j=0;j<7;j++){
			b[8*(3-i)+j] = a[i]%2;
			a[i]/=2;
		}
		if(a[i]==1){
			b[8*(4-i)-1] = 1;
		}
		else{
			b[8*(4-i)-1] = 0;
		}
	}
	return b;
}
int* getdecimal(int a[32]){
	int *b=new int[4];

	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			*(b+i)+=a[8*(3-i)+j]*pow(2,j);
		}
	}

	return b;
}