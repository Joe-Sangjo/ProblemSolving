#include <stdio.h>

#define MAX_RIBBON 100

int K;
int N;
int low, high, mid, numRibbonTape, max;
int sizeRibbonTape[MAX_RIBBON];

void search()
{
    mid = low + (high - low) / 2;
    numRibbonTape = 0;

    for (int i = 0; i < K ; i++) 
    {
        numRibbonTape += (sizeRibbonTape[i] / mid);
    }

    if (numRibbonTape >= N)
    {
        low = mid + 1;
        if (max < mid)
            max = mid;
    }
    else
    {
        high = mid - 1;
    }
}

int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) 
    {
        low = 1;
        high = 0 ;
        max = -1;

        scanf("%d %d", &K, &N);

        for (int i = 0; i < K; i++)
        {
            scanf("%d", &sizeRibbonTape[i]);
            if ( high < sizeRibbonTape[i] )
            {
                high = sizeRibbonTape[i] ;
            }
        }

        while (low <= high)
        {
            search();
        }
        printf("#%d ", test_case);
        printf("%d\n", max);
    }
    return 0;
}
