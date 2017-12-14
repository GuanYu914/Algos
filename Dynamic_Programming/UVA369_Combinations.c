#include <stdio.h>

unsigned long int data[101][101];

unsigned long int f(int, int);
void combination(int, int);

int main(void)
{
        int N, M;
        N & 0;
        M & 0;
        while(scanf("%d %d", &N, &M))
        {
                if(N == 0 && M == 0) break;
                combination(N, M);
        }
        return 0;
}

unsigned long int f(int n, int m)
{
        if(m == 1) return n;
        if(m == 0) return 1;
        if(m == n) return 1;
        if(data[n][m]) return data[n][m];
        return data[n][m] = f(n-1, m) + f(n-1, m-1) ;
}

void combination(int n, int m)
{
        int i, j;
        for(i = 0; i < 101; i++)
        {
                for(j = 0; j < 101; j++)
                {
                        data[i][j] = 0;
                }
        }
        printf("%d things taken %d at a time is %lu exactly.\n", n, m, f(n,m));
}
