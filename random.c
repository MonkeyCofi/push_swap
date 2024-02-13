#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
 * go through array up until index n
 * check each number for a duplicate
 * if the number is a duplicate, randomize it again
 * */
void	check_duplicate(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
				arr[j] = rand() % size;
		}
	}
}

int main(int ac, char **av)
{
	time_t s;

	srand(s);
	int num = atoi(av[1]);
	int i = -1;
	int numbers[num];
	while (++i < num)
	{
		numbers[i] = rand() % num;
	}
	check_duplicate(numbers, )
	for (int i = 0; i < num; i++)
		printf("%d ", numbers[i]);
	printf("\n");
}
