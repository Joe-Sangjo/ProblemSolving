#include <stdio.h>
#include <math.h>
int main(){
	int testNum,i,j,k,m;
	int p[100];
	int num,num2;
	int temp;
	int result;
	scanf("%d",&testNum);
	// testNum =4;
	for(i=0;i<testNum;i++){
		scanf("%d",&num);
	
		num2 = num;
		j=0;
		result = 0;
		temp=0;
		while(num>0){
			p[j] = num%10;
			num/=10;
			// printf("%d ",p[j]);
			j++;
		}
		m=j-1;
		for(k=0;k<j;k++,m--){
			temp += p[k]*pow(10,m);
		}
		num2+=temp;
		j=0;
		// printf("%d",num2);

		while(num2>0){
			p[j] = num2%10;
			num2/=10;
			j++;
		}
		for(k=0;k<j;k++){
			if(p[k]!=p[j-k-1]){
				result =1;
			}
			// printf("\n%d   %d\n", p[k],p[j-k-1]);
		}
		if(result == 0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}