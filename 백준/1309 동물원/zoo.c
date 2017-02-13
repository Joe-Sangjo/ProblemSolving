#include <stdio.h>
#include <stdlib.h>
int N;
int n;
int total;
void incre(int *p,int i);
void check(int *p);
int main(){
	int i,j,k,l;
	int *p;
	// scanf("%d",&N);
	N=4;
	p=(int *)malloc(sizeof(int)*n);
	total=0;
	
	// for(i=1;i<=N;i++){
	// 	n=i;
	// 	p[0]=1;
		n=1;
		incre(p,0);
	// }
	printf("%d\n",++total);

	free(p);
}
void incre(int *p,int i){
	if(i==n){
		return;
	}
	int j;
	while(p[i]<=N-n+i+1){
		p[i+1]=p[i]+1;
		if(i==n-1){
			for(j=0;j<=i;j++){
				printf("%d ",p[j]);
			}
			// printf("\t\t\t\t");
			printf("\n");
			check(p);

			// printf("%d\n",total);
	
		}
		incre(p,i+1);
		p[i]++;
	}
}

void check(int *p){
	int i;
	int t=2;
	for(i=0;i<n-1;i++){
		if(p[i+1]-p[i]==1){
		}
		else{
			t*=2;
		}
	}
	total+=t;
}