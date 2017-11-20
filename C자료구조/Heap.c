#include <stdio.h>

#define NUM_DATA (8)
#define MAX_DATA (NUM_DATA)
#define MAX_HEAP (MAX_DATA + 1)
#define LAST_NODE (MAX_DATA)

int heap[MAX_HEAP];
int lastnode = 0;


int exam[NUM_DATA+1] = {0,4,8,2,7,1,3,6,5}; // 0번 index 공간 무시

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",heap[j]);}printf(")\n");}


int Heap_Push_Minheap(int *heap, int size, int *lastnode, int d);
int Heap_Pop_Minheap(int *heap, int *lastnode, int *d);
int Heap_Push_Maxheap(int *heap, int size, int *lastnode, int d);
int Heap_Pop_Maxheap(int *heap, int *lastnode, int *d);
void Heap_Sort(int *data, int cnt, int order);


int Heap_Pop_Minheap(int *heap, int size, int *lastnode, int d){

	int n, p, temp;

	if(*lastnode == size) return 0;

	heap[++(*lastnode)] = d;

	n = *lastnode; p = n / 2;

	while(p > 0){

		if(heap[n] < heap[p]){

			temp = heap[n];
			heap[n] = heap[p];
			heap[p] = temp;
			n = p; p = n / 2;
		}
		else break;

	}
	return 1;
}



int Heap_Pop_Minheap(int *heap, int *lastnode, int *d){


	int n, c, lc, rc, temp;

	if(*lastnode == 0) return 0;


	*d = heap[1];
	heap[1] = heap[(*lastnode)--];

	n = 1; lc = 2; rc = 3;
	while(lc <= *lastnode){

		if(*lastnode == lc) c = lc;
		else c = (heap[lc] < heap[rc]) ? (lc) : (rc);

		if(heap[c] < heap[n]){
			temp = heap[c];
			heap[c] = heap[n];
			heap[n] = temp;
			n = c; lc = n*2; rc = lc + 1;
		}
		else break;
	}

	return 1;

}




int Heap_Push_Maxheap(int *heap, int size, int *lastnode, int d){

	int n, p, temp;

	if(*lastnode == size) return 0;

	heap[++(*lastnode)] = d;

	n = *lastnode; p = n / 2;

	while(p > 0){

		if(heap[n] > heap[p]){
			temp = heap[n];
			heap[n] = heap[p];
			heap[p] = temp;
			n = p; p = n / 2;
		}
		else break;
	}
	return 1;
}




int Heap_Pop_Maxheap(int * heap, int *lastnode, int *d){
	int n, c, lc, rc, temp;

	if(*lastnode == 0) return 0;


	*d = heap[1];
	heap[1] = heap[(*lastnode)--];

	n = 1; lc = 2; rc = 3;

	while(lc <= *lastnode){

		if(*lastnode == lc) c = lc;
		else c = (heap[lc] > heap[rc] ? (lc) : (rc));

		if(heap[c] > heap[n]){

			temp = heap[c];
			heap[c] = heap[n];
			heap[n] = temp;
			n = c; lc = n*2; rc = lc + 1;
		}
		else break;
	}
	return 1;
}



typedef int (*HEAP_PUSH)(int *, int *, int *, int);
typedef int (*HEAP_POP)(int *, int *, int *);


void Heap_Sort(int *data, int cnt, int order){

	int i, ret, lastnode = 0;
	HEAP_PUSH Heap_Push[2] = {Heap_Push_Maxheap, Heap_Push_Minheap};
	HEAP_POP Heap_Pop[2] = {Heap_Pop_Maxheap, Heap_Pop_Minheap};


	for(i = 0; i <cnt; i++){

		Heap_Push[order](data - 1, MAX_DATA, &lastnode, data[i]);
	}


	for(i = cnt - 1; i >= 0; i--){
		Heap_Pop[order](data - 1, &lastnode, &ret);
		data[i] = ret;
	}

}



