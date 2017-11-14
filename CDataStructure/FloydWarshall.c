#include <stdio.h>
#define INFINITY 999999

int weight[101][101];
int result[101][101];

void floyd(int n) 
{
    int i, j, k;

    for (k = 0; k < n; k++) 
    {
        for (i = 0; i < n; i++) 
        {
            if (k == 0) 
            {
                for (j = 0; j < n; j++) 
                {
                    result[i][j] = weight[i][j];
                }
            }
            for (j = 0; j < n; j++) 
            {
                if (result[i][k] + result[k][j] < result[i][j])
                {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
}

int main() 
{
    int T;
    int n, m, i, j;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) 
    {
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n; j++) 
            {
                weight[i][j] = INFINITY;
            }
            weight[i][i] = 0;
        }

        for (i = 0; i < m; i++) 
        {
            int st, en, w;
            scanf("%d %d %d", &st, &en, &w);
            if (weight[st-1][en-1] > w)
            {
                weight[st-1][en-1] = w;
            }
        }

        floyd(n);

        printf("#%d\n", test_case);
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n; j++) 
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}
