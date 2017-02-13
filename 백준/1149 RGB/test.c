#include <stdio.h>
void hi(int a, int b);
int main(){
	int a,b,c;
	int i;
	for(i=0;i<10;i++){
		scanf("%d %d %d",&a,&b,&c);
		printf("%d %d %d\n", a,b,c);
	}
	return 0;
}

void hi(int a, int b){
	printf("%d %d", a, b);
}