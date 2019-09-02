#include <stdio.h>

int heap[500002];
int n; //heap의 size
int N; //입력 받는 zie
void swap(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

//max_heap
void push(int p) {
	//root이거나 부모보다 크거나 같다면,
	if (p <= 1 || heap[p / 2] >= heap[p]) return;
	swap(heap[p / 2], heap[p]);
	push(p / 2);
}

void pop(int p) {

	//왼쪽 자식
	int next = p * 2;
	
	//자식이 현재 heap size보다 크면 끝남
	if (next > n) return;
	
	//max_heap은 왼쪽 자식과 오른쪽 자식 중 더 큰것과 교환한다.
	// -> 그래야 max_heap이 성립(부모는 항상 자식보다 크다)
	// next <= n 이 아닌 것은, next + 1 <= n 이라는 의미
	if (next < n && heap[next] < heap[next + 1]) next++;

	//만약 자식보다 부모가 더 크면 끝나는 상황
	if (heap[p] >= heap[next]) return;
	
	//바꾼다.
	swap(heap[p], heap[next]);
	
	//다시 바꾼 자식에서 확인한다.
	pop(next);
}

//max_heap sort는 오름차순
//min_heap sort는 내림차순
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	n = N;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &heap[i]);
		push(i);
	}
	
	for (int i = 1; i <= N; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	while (n > 1) {
		//root는 가장 크므로 미리 마지막에 놔둔다
		swap(heap[1], heap[n--]);
		pop(1);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	return 0;
}
