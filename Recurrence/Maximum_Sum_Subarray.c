#include <stdio.h>

int maximum_sum_subarray(int[]);

int main(void)
{
	int a[10] = {1, 2, -6, 3, -2, 4, -1, 3, 2, -4};
	printf("max subarray sum is: %d\n", maximum_sum_subarray(a));	
	return 0;
}

//with no value fatching
/*
int maximum_sum_subarray(int a[])
{
    int max_sum = 0, sum = 0;
    for (int i=0; i<10; ++i)
    {
        sum += a[i];            // 累計總和
        if (sum < 0) sum = 0;   // 零總比負數好
 
        // 隨時記錄最大值
        if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
}
*/

//with value fetching
/*
int maximum_sum_subarray(int a[])
{
    int max_sum = -1e9, sum = 0;
    for (int i=0; i<10; ++i)
    {
        // 先前累積的不是負數，加了就更大。
        if (sum > 0) sum += a[i];
        // 先前累積的若是負數，寧可不加。
        else sum = a[i];
 
        // 隨時記錄最大值
        if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
}
*/

int maximum_sum_subarray(int a[])
{
    int max_sum = 0, sum = 0;
    int start = 0, end = 0, temp_start = 0;
 
    for (int i=0; i<10; ++i)
    {
        sum += a[i];
 
        if (sum < 0)
        {
            sum = 0;
            temp_start = i+1;   // 重新設定起點是下一個數字
        }
 
        if (sum > max_sum)
        {
            max_sum = sum;
            start = temp_start;
            end = i;
        }
    }
 
    if (start > end)
        printf("什麼數字都不取\n");
    else
        printf("From index[%d] to index[%d]\n", start, end);
 
    return max_sum;
}
