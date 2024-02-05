#include <stdio.h>
#include "push_swap.h"

int main(void)
{
	// int n[] = {-2147483648, -120,-1, 0, 3, 1,-12,-17, 5, 10, 20, -3, 15, 42, 65, 1290, 480,-5, 120, 666, 2147483647};
	int n[] = {5, 1, 2, 4, 3, 6, 10, 0, -50, -10, -8, 20};
	// printf("Partition: %d\n", partition(n, 0, 4));
	for (int i = 0; i < sizeof(n)/sizeof(int); i++)
		printf("%d ", n[i]);
	printf("\n");
	// int size = sizeof(n) / sizeof(int);
	// mofm(n, size);
	// for (int i = 0; i < size; i++)
	// {
	// 	for (int j = 0; j < size - i - 1; j++)
	// 	{
	// 		if (n[j] > n[j + 1])
	// 		{
	// 			int temp = n[j];
	// 			n[j] = n[j + 1];
	// 			n[j + 1] = temp;
	// 		}
	// 	}
	// }
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%d ", n[i]);
	// }
	// printf("\n");
	// if (size % 2)
	// 	printf("Median is %d\n", n[size / 2 - 1] + n[size / 2] / 2);
	// else
	// 	printf("Median is %d\n", n[size / 2]);
}