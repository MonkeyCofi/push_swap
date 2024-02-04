#include <stdio.h>
#include "push_swap.h"

int main(void)
{
	// int n[] = {-2147483648, -120,-1, 0, 3, 1,-12,-17, 5, 10, 20, -3, 15, 42, 65, 1290, 480,-5, 120, 666, 2147483647};
	int n[] = {5, 1, 3, 4, 2, 0, 7, 6, 10, 9};
	int size = sizeof(n) / sizeof(int);
	mofm(n, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (n[j] > n[j + 1])
			{
				int temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", n[i]);
	}
	printf("\n");
	if (size % 2)
		printf("Median is %d\n", n[size / 2 - 1] + n[size / 2] / 2);
	else
		printf("Median is %d\n", n[size / 2]);
}