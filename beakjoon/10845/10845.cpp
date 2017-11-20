#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

#define MOD 5000

int queue[MOD];

int front, back;


void push(int in) {
	if (front == back || front % MOD != back % MOD) {
		queue[back++] = in;
	}
}

int FRONT() {
	if (front == back) return -1;
	else return queue[front % MOD];
}
int BACK() {
	if (front == back) return -1;
	else return queue[(back - 1) % MOD];
}
int size() {
	return back - front;
}
int pop() {
	if (front == back) return -1;
	else return queue[front++ % MOD];
}
bool empty() {
	return front == back;
}


int n;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string in;
	scanf("%d", &n);
	front = 0, back = 0;
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in == "push") {
			int a; scanf("%d", &a);
			push(a);
		}
		else if (in == "front") {
			printf("%d\n", FRONT());
		}
		else if (in == "back") {
			printf("%d\n", BACK());
		}
		else if (in == "size") {
			printf("%d\n", size());
		}
		else if(in == "pop") {
			printf("%d\n", pop());
		}
		else if (in == "empty") {
			printf("%d\n",empty());
		}
	}
	return 0;
}