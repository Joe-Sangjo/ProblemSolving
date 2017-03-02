#include <stdio.h>

int main(){
	int num;
	int building[500][500];
	int i,j;
	int temp;
	scanf("%d\n",&num);
	for(i=0;i<num;i++){
		for(j=0;temp!=-1;j++){
			scanf("%d",&temp);
			building[i][j]=temp;
			printf("%d ",building[i][j]);
		}
		printf("\n");
	}

	return 1;
}