#include <stdio.h>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void insertionSort(void)
{
	int temp;
	int i;
	int j;

	for (i = 1; i < num; i++)
	{
		temp = input[i];
		j = i - 1;

		while ((temp < input[j]) && (j >= 0))
		{
			input[j + 1] = input[j];
			j = j - 1;
		}
		input[j + 1] = temp;
	}
}

void printResult(void)
{
	int i;

	for (i = 0; i < num; ++i)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
}

int main(void)
{
	int T;
	int test_case;
	int i;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &num);
		for (i = 0; i < num; i++)
		{
			scanf("%d", &input[i]);
		}
		insertionSort();
		printf("#%d ", test_case);
		printResult();
	}

	return 0;
}
