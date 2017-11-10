#include <stdio.h>
#include <string.h>
 
void do_multiply(int, int, int*, int, int, int*, int*);
void display(int, int, int*);
 
int main()
{
    int m1, n1, m2, n2, i, j, k;

    printf("Enter rows and columns for Matrix A (input format(row col)): ");
    scanf("%d %d", &m1, &n1);
	int first[m1][n1];
	memset(first, 0, sizeof first);

    printf("Enter rows and columns for Matrix B (input format(row col)): ");
    scanf("%d %d", &m2, &n2);
	int second[m2][n2];
	memset(second, 0, sizeof second);

	int multiply[m1][n2];
	memset(multiply, 0, sizeof multiply);
	display(m1, n2, (int*)multiply);
	
    if (n1 != m2)
    {
        printf("Matrix multiplication not possible.\n");
    }
    else
    {		
        printf("Enter elements in Matrix A:\n");
        for(i = 0; i < m1; i++)
		{
        	for (j = 0; j < n1; j++)
        	{
            	scanf("%d", &first[i][j]);
        	}
		}
		printf("List Matrix A: \n");
		display(m1, n1, (int*)first);
		
        printf("\nEnter elements in Matrix B:\n");
        for(i = 0; i < m2; i++)
		{
        	for(j = 0; j < n2; j++)
        	{
            	scanf("%d", &second[i][j]);
        	}
		}	
		printf("List Matrix B: \n");
		display(m2, n2, (int*)second);
    }
	
    do_multiply(m1, n1, (int*)first, m2, n2, (int*)second, (int*)multiply);
    printf("On matrix multiplication of A and B the result is:\n");
    display(m1, n2, (int*)multiply);
}
 
void do_multiply (int m1, int n1, int* first, int m2, int n2, int* second, int* multiply)
{
	// avoid to reinitialize variable
    static int i = 0, j = 0, k = 0;
 
    if (i >= m1)
    {
        return;
    }
    else if (i < m1)
    {
        if (j < n2)
        {
            if (k < m2)
            {
				//multiply[i][j] = first[i][k] * second[k][j];
				*((multiply + n2*i) + j) = *((multiply + n2*i) + j) + (*((first + n2*i) + k) * *((second + n2*k) + j));
                k++;
                do_multiply(m1, n1, first, m2, n2, second, multiply);
            }
            k = 0;
            j++;
            do_multiply(m1, n1, first, m2, n2, second, multiply);
        }
        j = 0;
        i++;
        do_multiply(m1, n1, first, m2, n2, second, multiply);
    }
}
 
void display(int m1, int n2, int* data)
{
    int i, j;
 
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            //printf("%d  ", multiply[i][j]);
            printf("%d\t", *((data + i*n2) + j));
        }
        printf("\n");
    }
}
