#include <stdio.h>

int size;
int count=0;
void visit(int N, int n,int array[10]);
int main(){
	int array[10];
	int i;
	// scanf("%d",&size);
	size=10;
	// for(i=1;i<10;i++){
		for(i=0;i<10;i++){
			array[i] = 0;
		}
		visit(0,1,array);
	// }
	printf("\n");
	return 0;
}
void visit(int N, int n,int array[10]){
	int i;
	
	for(i=0;i<10;i++){
		printf("%d ",array[i] );
	}
	printf("\n");
	printf("%d \n",n);
	if(n==size){
		printf("%d \n",size );

		for(i=0;i<10;i++){
			if(array[i]==0){
				return;
			}
		}
		count++;
		return;
	}
	else{
		array[N]++;
		if(N==9){
			printf("%d ",N);
		}
		// printf("%d\n",N);
		if(N==0){
			visit(N+1,n+1,array);
		}
		else if(N==9){
			visit(N-1,n+1,array);
		}
		else{
			// if(N==8){
			// 	printf("%d ",N);
			// }
			visit(N+1,n+1,array);
			visit(N-1,n+1,array);
		}
	}
}