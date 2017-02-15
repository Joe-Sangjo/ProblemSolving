#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define SMALL 1;

int FenceNum;
int Fence[20001];
int area;
int width;
void rectangle(int height,int position, int way);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);
	int TC;
	cin>>TC;
	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>FenceNum;
		area = SMALL;
		memset(Fence, 0, 20001*sizeof(int));
		for(int i = 0 ; i < FenceNum ; i ++)
			cin>>Fence[i];

		for(int i = 0 ; i < FenceNum; i++){
			width = 1;
			if(Fence[i] == 1){
				area = max(area, FenceNum);
			}
			else{
				rectangle(Fence[i], i-1, -1);
				rectangle(Fence[i], i+1, 1);
				area = max(area, width * Fence[i]);
			}
		}	
		cout<<area<<endl;
	}
	return 0;
}

void rectangle(int height,int position, int way){

	if(position < 0 || position > FenceNum-1) return;

	if(Fence[position] < height) return;
	else{
		width++;
		rectangle(height,position+way,way);
	}
}