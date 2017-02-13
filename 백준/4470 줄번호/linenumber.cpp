#include <stdio.h>
#include <stdlib.h>
int main(){
	int num;
	int i;
	char **st;
	scanf("%d\n",&num);
	st = (char**)malloc(sizeof(char*) *num);
	for(i=0;i<num;i++){
		st[i] = (char*)malloc(sizeof(char)*50);
	}
	for(i = 0; i<num; i++){
		gets(st[i]);
		printf("%d. %s\n",i+1,st[i]);
		free(st[i]);
	}
	free(st);
}