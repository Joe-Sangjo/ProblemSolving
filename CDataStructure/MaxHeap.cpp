#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int heap[100001];
int size = 0;

void swap(int& a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}
int pop() {
	if (size == 0) return 0;

	int ret = heap[0];

	heap[0] = heap[--size];

	int here = 0;

	while (true) {
		
		int left = here * 2 + 1, right = here * 2 + 2;

		int next = here;

		if (left < size && heap[next] < heap[left])
			next = left;
		if (right < size && heap[next] < heap[right])
			next = right;
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}
	return ret;
}

void push(int newValue) {

	heap[size++] = newValue;
	if (size == 1) return;

	int idx = size - 1;
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}

}
int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		int in; scanf("%d", &in);
		if (in == 0) {
			printf("%d\n", pop());
		}
		else {
			push(in);
		}
	}


	return 0;
}
