#include <stdio.h>

#define MAX 1000

int countA, countB;
int matchA[MAX];
int matchB[MAX];
int adj[MAX][MAX];
int visited[MAX];

int dfs(int a)
{
	int b;

	if (visited[a])
	{
		return 0;
	}

	visited[a] = 1;

	for (b = 0; b < countB; ++b)
	{
		if (adj[a][b] && (matchB[b] == -1 || dfs(matchB[b])))
		{
			matchA[a] = b;
			matchB[b] = a;
			return 1;
		}
	}

	return 0;
}

int bipartiteMatch(void)
{
	int size = 0;
	int start;
	int i;
	for (start = 0; start < countA; ++start)
	{
		for (i = 0; i < countA; i++)
		{
			visited[i] = 0;
		}
		if (dfs(start))
		{
			size++;
		}
	}
	return size;
}

void initialize(void) 
{
	int i, j;
	for (i = 0; i < countA; i++)
	{
		matchA[i] = -1;
		for (j = 0; j < countB; j++)
		{
			adj[i][j] = 0;
		}
	}

	for (i = 0; i < countB; i++)
	{
		matchB[i] = -1;
	}
}

int main(int argc, char* argv[]) 
{

	int T, adjCount;
	
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &countA);
		scanf("%d", &countB);

		initialize();

		scanf("%d", &adjCount);

		for (int i = 0; i < adjCount; i++) 
		{
			int a, b;
			scanf("%d", &a);
			scanf("%d", &b);
			adj[a - 1][b - 1] = 1;
		}
 		printf("#%d %d\n", test_case, bipartiteMatch());
	}
	return 0;
}
