#include <stdio.h>
#include <stdlib.h>

#define MAX_N 25
#define MAX_M 25
#define CONNECTED 1
#define NOT_CONNECTED 0
#define NOT_UPDATED_YET 0
#define NOT_VISITED -1
#define DUPLICATE -2

int map[MAX_N][MAX_N] = {0, };
int count[MAX_N] = {0, };
int test_case, n, m;

typedef struct {
	int queue[MAX_N];
	int cur_ptr;
	int last_ptr;
} Queue;

void queue_reset(Queue* queue) 
{
	queue->cur_ptr = 0;
	queue->last_ptr = 0;
}

int queue_has_item(Queue* queue) 
{
	return queue->last_ptr - queue->cur_ptr > 0;
}

int queue_dequeue(Queue* queue) 
{
	return queue->queue[queue->cur_ptr++];
}

void queue_enqueue(Queue* queue, const int item) 
{
	queue->queue[queue->last_ptr++] = item;
}

typedef struct {
	int stack_set[MAX_N];
	int last_ptr;
} Stack;


void stack_reset(Stack* stack) 
{
	stack->last_ptr = 0;
}

int stack_has_item(Stack* stack) 
{
	return stack->last_ptr > 0;
}

int stack_peek(Stack* stack) 
{
	return stack->stack_set[stack->last_ptr - 1];
}

int stack_pop(Stack* stack) 
{
	return stack->stack_set[--stack->last_ptr];
}

void stack_set_mark_duplicate(Stack* stack, const int item) 
{
	int i;
	for (i = 0; i < stack->last_ptr; i++) 
	{
		if (stack->stack_set[i] == item)
		{
			stack->stack_set[i] = DUPLICATE;
		}
	}
}

void stack_set_push(Stack* stack, const int item) 
{
	stack_set_mark_duplicate(stack, item);

	stack->stack_set[stack->last_ptr++] = item;
}

typedef struct _Node {
	int item;
	struct _Node* prev;
} Node;

void node_reset(Node* node) 
{
	Node* cur = node->prev;
	while (cur) 
	{
		Node* temp = cur;
		cur = temp->prev;
		free(temp);
	}
	node->prev = NULL;
}

void node_push(Node* node, Node* other) 
{
	if (node->prev == NULL) 
	{
		node->prev = other;
		return;
	}

	Node* head = node;
	while (head->prev != NULL) 
	{
		head = head->prev;
	}

	head->prev = other;
}

int connected(const int src, const int dest) 
{
	return map[src][dest] == CONNECTED;
}

void put_starting_point(Queue* queue)
{
	int i;
	for (i = 0; i < n; i++) 
	{
		if (count[i] == 0) 
		{
			queue_enqueue(queue, i);
		}
	}
}

void init(Node* nodes) 
{
	int i;
	for (i = 0; i < MAX_N; i++) 
	{
		nodes[i].item = i;
		nodes[i].prev = NULL;
	}
}

void reset(Stack* stack, Queue* queue, Node* nodes) 
{
	int i, j;
	for (i = 0; i < MAX_N; i++) 
	{
		for (j = 0; j < MAX_N; j++) 
		{
			map[i][j] = 0;
		}
	}
	for (i = 0; i < MAX_N; i++) 
	{
		count[i] = 0;
	}

	stack_reset(stack);
	queue_reset(queue);
	for (i = 0; i < MAX_N; i++) 
	{
		node_reset(&nodes[i]);
	}
}


void traverse(Node* nodes, const int idx, Stack* stack) 
{
	stack_set_push(stack, nodes[idx].item);

	Node* cur = nodes[idx].prev;
	while (cur) 
	{
		traverse(nodes, cur->item, stack);
		cur = cur->prev;
	}
}

int main(void) 
{
	int dest, tc, i;
	Queue queue;
	Stack stack;
	Node nodes[MAX_N];
	init(nodes);

	scanf("%d", &test_case);

	for (tc = 1; tc <= test_case; tc++) 
	{
		scanf("%d %d", &n, &m);
		scanf("%d", &dest);

		reset(&stack, &queue, nodes);

		for (i = 0; i < m; i++) 
		{
			int src, dest;
			scanf("%d %d", &src, &dest);
			map[src - 1][dest - 1] = CONNECTED;
			count[dest - 1]++;
		}

		put_starting_point(&queue);

		while (queue_has_item(&queue)) 
		{
			int src = queue_dequeue(&queue);
			for (i = 0; i < n; i++)
			{
				if (connected(src, i)) 
				{
					Node* node = (Node*) malloc(sizeof(Node));
					node->item = src;
					node->prev = NULL;
					node_push(&nodes[i], node);

					count[i]--;
					if (count[i] == 0)
					{
						queue_enqueue(&queue, i);
					}
				}
			}
		}

		printf("#%d  ", tc);
		if (!nodes[dest - 1].prev) 
		{
			printf("Not reached");
		} 
		else 
		{
			traverse(nodes, dest - 1, &stack);
			while (stack_has_item(&stack)) 
			{
				int item = stack_pop(&stack);
				if (item == DUPLICATE)
				{
					continue;
				}

				printf("%d ", item + 1);
			}
		}
		printf("\n");
	}

	return 0;
}
