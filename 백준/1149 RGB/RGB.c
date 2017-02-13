#include <stdio.h>

int totalcost;
int NumOfHouse;
void sum(int cost[][3], int color, int nownum, int sumofcost);
int main(){
	int a;
	int cost[1000][3];
	int i,j,k;
	int cost0,cost1,cost2;
	int temp;
	// scanf("%d",&a);
	a = 3;
	// for(i=0;i<a;i++){
	// 	scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);
	// }
	NumOfHouse = a;
	cost[0][0] = 26, cost[0][1] = 40, cost[0][2] = 83;
	cost[1][0] = 49, cost[1][1] = 60, cost[1][2] = 57;
	cost[2][0] = 13, cost[2][1] = 89, cost[2][2] = 99;
	
	totalcost = 1000000;
	sum(cost, 0, 0, 0);
	cost0 = totalcost;
	totalcost = 1000000;
	sum(cost, 1, 0, 0);
	cost1 = totalcost;
	totalcost = 1000000;
	sum(cost, 2, 0, 0);
	cost2 = totalcost;
	if(cost0>cost1){
		temp = cost1;
	}
	else{
		temp = cost0;
	}
	if(cost2<temp){
		temp=cost2;
	}
	// printf("%d\n",temp);
	printf("%d %d %d\n",cost0, cost1, cost2);
	return 0;
}

void sum(int cost[][3], int color, int nownum, int sumofcost){
	if(nownum==NumOfHouse-1){
		sumofcost+=cost[nownum][color];
		if(totalcost>sumofcost){
			totalcost = sumofcost;
		}
		return;
	}
	else{
		sumofcost +=cost[nownum][color];
		nownum++;
		if(color == 0){
			sum(cost, 1,nownum,sumofcost);
			sum(cost, 2,nownum, sumofcost);
		}
		else if (color == 1){
			sum(cost,0,nownum, sumofcost);
			sum(cost,2,nownum, sumofcost);
		}
		else{
			sum(cost,0,nownum,sumofcost);
			sum(cost,1,nownum,sumofcost);
		}
	}
}