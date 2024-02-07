#include <stdio.h>

int	partition(int arr[], int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = pivot;
	arr[right] = temp;
	return (i + 1);
}

void	quicksort(int a[], int left, int right)
{
	int	part;

	if (left >= right || left < 0)
		return ;
	part = partition(a, left, right);
	quicksort(a, left, part - 1);
	quicksort(a, part + 1, right);
}

int	quickselect(int a[], int left, int right, int k)
{
	int	p;

	if (k > 0 || k <= right - left + 1)
	{
		p = partition(a, left, right);

		if (p - left > k - 1)
			return (quickselect(a, left, p - 1, k));
		return (quickselect(a, p + 1, right, k - p + left - 1));
	}
	return (0);
}

void	print_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", a[i]);
		else
			printf("%d ", a[i]);
	}
}

int main(void)
{
	int a[] = {8, 3, 4, 2, 1, 5, 7};
	int size = sizeof(a) / sizeof(int);
	// quicksort(a, 0, size - 1);
	print_array(a, size);
	// figuring out how many chunks to have
	printf("%d\n", 500 / 4 + (100 % 2));
}