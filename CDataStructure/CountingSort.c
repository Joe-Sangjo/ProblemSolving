#include <stdio.h>

#define MAX_N 100
#define MAX_DIGIT 10

int N;  // # of data set
int arr[MAX_N];
int cnt[MAX_DIGIT];
int sortedArr[MAX_N];

void calculateDigitNumber()
{
    for (int i = 0; i < N; i++)
    {
        cnt[arr[i]]++;
    }

    for (int i = 1; i < MAX_DIGIT; i++)
    {
        cnt[i] = cnt[i-1] + cnt[i];
    }
}

void executeCountingSort()
{
    for (int i = N-1; i >= 0; i--)
    {
        sortedArr[--cnt[arr[i]]] = arr[i];
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) 
    {
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }

        // initialize
        for (int i = 1; i < MAX_DIGIT; i++)
        {
            cnt[i] = 0;
        }

        calculateDigitNumber();
        executeCountingSort();

        //print the sorted digits
        printf("#%d ", test_case);
        for (int i = 0; i < N; i++) 
        {
            printf("%d ", sortedArr[i]);
        }
        printf("\n");
    }
    return 0;
}
