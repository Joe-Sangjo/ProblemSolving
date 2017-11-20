#include <stdio.h>

#define MAX_V 10

const int INF = 987654321;
int V;

typedef struct
{
	int queueArray[MAX_V];
	int front;
	int rear;
}Queue;

void push(Queue *q, int item)  
{
	if ((q->rear + 1) % MAX_V == q->front)
	{
		return;
	}
	q->queueArray[q->rear] = item;
	q->rear = (q->rear + 1) % MAX_V;
}
void pop(Queue * q)
{
	if (q->front == q->rear)
	{
		return;
	}
	q->front = (q->front + 1) % MAX_V;
}

int getFront(Queue * q)
{
	return q->queueArray[q->front];
}

int isEmpty(Queue *q)
{
	if (q->rear == q->front) 
	{ 
		return 1;
	}
	else
	{
		return 0;
	}
}

int networkFlow(int source, int sink, int capacity[][MAX_V])
{
	int flow[MAX_V][MAX_V] = { 0, };
	int parent[MAX_V];
	int totalFlow = 0;
	int p;
	while (1)
	{
		for (p = 0; p < V; p++)
		{
			parent[p] = -1;
		}

		Queue q;
		
		q.front = 0;
		q.rear = 0;

		parent[source] = source;
		push(&q, source);

		while (!isEmpty(&q)) 
		{
			int here = getFront(&q); pop(&q);
			int there;
			for (there = 0; there < V; ++there) 
			{
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					push(&q, there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == -1)
		{
			break;
		}

		int amount = INF;
		for (p = sink; p != source; p = parent[p]) 
		{
			if (capacity[parent[p]][p] - flow[parent[p]][p] > amount) 
			{
				amount = amount;
			}
			else {
				amount = capacity[parent[p]][p] - flow[parent[p]][p];
			}
		}

		for (p = sink; p != source; p = parent[p]) 
		{
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int main(int argc, char** argv)
{
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int capacity[MAX_V][MAX_V] = { 0, };
		int E, here, there, C, answer;

		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; ++i) 
		{
			scanf("%d %d %d", &here, &there, &C);
			capacity[here][there] = C;
		}

		answer = networkFlow(0, V - 1, capacity);

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}


