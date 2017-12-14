#include <stdio.h>
#define N 100

int arr[N][N];

int max(int a, int b)
{
        return (a > b) ? a : b;
}

int max_subarr(int data[], int len)
{
        int i = 0, max_sum = -32760, sum = 0;
        for (i = 0; i < len; i++)
        {
                if(sum > 0)
                {
                        sum += data[i];
                }
                else
                {
                        sum = data[i];
                }
                if(sum > max_sum)
                {
                        max_sum = sum;
                }
        }
        return max_sum;
}

int main(void)
{
        int i, j, k, n, tmp, M, sum[N];
        while(scanf("%d\n", &n) != EOF)
        {
                M = -32760;
                for(i = 0; i < n; i++)
                {
                        for(j = 0; j < n; j++)
                        {
                        scanf("%d", &arr[i][j]);
                        }
                }

                for(i = 0; i < n; i++)
                {
                        for(j = 0; j < n; j++)
                        {
                                sum[j] = arr[i][j];
                        }

                        tmp = max_subarr(sum, n);
                        M = max(tmp, M);
                        for(j = i+1; j < n; j++)
                        {
                                for(k = 0; k < n; k++)
                                {
                                        sum[k] += arr[j][k];
                                }
                                tmp = max_subarr(sum, n);
                                M = max(tmp, M);
                        }
                }
                printf("%d\n", M);
        }
        return 0;
}


