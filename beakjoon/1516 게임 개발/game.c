#include <stdio.h>
int search(int *visit,int a);
int main(){
	int num;
	int building[500][500];
	int visit[500];
	int i,j,k,p,a,b,c;
	int temp;
	int vi_in;
	scanf("%d\n",&num);
	for(i=0;i<num;i++){
		temp =0;
		for(j=0;temp!=-1;j++){
			scanf("%d",&temp);
			building[i][j]=temp;
		}q
	}
/////////////////////////////////////////////////////
	// num = 5;
	// building[0][0] = 10; building[0][1] = -1;
	// building[1][0] = 10; building[1][1] = 1; building[1][2] = -1;
	// building[2][0] = 4; building[2][1] = 1; building[2][2] = -1;
	// building[3][0] = 4; building[3][1] = 3; building[3][2] = 1; building[3][3] = -1;
	// building[4][0] = 3; building[4][1] = 3; building[4][2] = -1;

////////////////////////////////////////////////////
	for(i=0;i<num;i++){
		for(k=0;k<500;k++){
			visit[k]=-100;
		}
		p=0;
		vi_in=0;
		for(j=1;building[i][j]!=-1;j++){
			a = building[i][j];
			for(k=1;building[a][k]!=-1;k++){
				visit[vi_in++] = building[a-1][k];
			}
			if(search(visit,a)==-1){
				building[i][0] += building[a-1][0];
			}
			

		}
		printf("%d\n",building[i][0]);
	}

	return 1;
}
int search(int *visit,int a){
	int i;
	for(i=0;i<500;i++){
		if(visit[i]==a){
			return 1;
		}
	}
	return -1;
}