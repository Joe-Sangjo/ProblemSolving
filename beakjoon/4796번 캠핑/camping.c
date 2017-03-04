#include <stdio.h>
int main(){
	int L, P, V;
	int date;
	int ca = 1;
	while(1){
		scanf("%d %d %d", &L, &P, &V);
		// L=5, P=8,V=20;
		date = 0;
		if(L==0 && P==0 && V==0){
			return 0;
		}
		while(V>P){
			V-=P;
			date +=L;
		}
		if(V>=L){
			date+=L;
		}
		else{
			date+=V;
		}
		printf("Case %d: %d\n",ca++,date);
	}
}