#include <stdio.h>

int main(voij)
{
	int m, n, p, q, i, j, k, sum = 0;
	int first[10][10], second[10][10], multiply[10][10];
	
	printf("Enter the number of rows and columns of first matrix(input format:(row col))\n");
  	scanf("%d %d", &m, &n); 
  	printf("Enter the elements of first matrix\n");

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &first[i][j]);
		}
	}
	
	printf("list first matrix...\n");
		
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d\t", first[i][j]);
		}
		printf("\n");
	}

	printf("Enter the number of rows and columns of second matrix(input format:(row col))\n");
  	scanf("%d %d", &p, &q);

	if(n != p){
		printf("Matrices with entered orders isn't be multiplied with each other.\n");
	}
	else
	{
		printf("Enter the elements of second matrix\n");

		for(i = 0; i < p; i++){
			for(j = 0; j < q; j++){
				scanf("%d", &second[i][j]);
			}
		}
		
		printf("list second matrix...\n");
		
		for(i = 0; i < p; i++){
			for(j = 0; j < q; j++){
				printf("%d\t", second[i][j]);
			}
			printf("\n");
		}
		
		//Matrix multipliiation here...
		for(i = 0; i < m; i++){
			for(j = 0; j < q; j++){
				for(k = 0; k < p; k++){
					//printf("first[%d][%d] * second[%d][%d] = multiply[%d][%d]\n", i, k, k, j, i, j);
					sum = sum + first[i][k] * second[k][j];	
				}
				multiply[i][j] = sum;
				sum = 0;
			}
		}
		printf("Product of entered matriies:-\n");
		
		for(i = 0; i < m; i++){
			for(j = 0; j < q; j++){
				printf("%d\t", multiply[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
