#include <stdio.h>

int main(void){
	int n[] = {5, 1, 4, 3,6, 2};
	int size = sizeof(n) / sizeof(int);
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
	if (size % 2)
		printf("Median is %d\n", n[size / 2 - 1] + n[size / 2] / 2);
	else
		printf("Median is %d\n", n[size / 2]);
}