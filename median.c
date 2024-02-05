/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/05 17:13:55 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dup stack elements into array
int	*arrayify(t_stack *stack)
{
	int	*arr;
	int	index;

	if (!stack)
		return (NULL);
	index = 0;
	arr = malloc(sizeof(int) * ft_stacksize(stack));
	if (!arr)
		exit(EXIT_FAILURE);
	while (stack)
	{
		arr[index++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

// sor the array
// return the middle element of the array
int	get_median(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	if (n % 2 == 1)
		return (arr[n / 2]);
	return ((arr[n / 2 - 1] + arr[n / 2]) / 2);
}

int	mofm(int *arr, int n)
{
	int		median;
	int		*medians;
	double	n_medians;
	int		i;

	if (n <= 5)
		return (get_median(arr, n));
	n_medians = n / 5;
	i = 0;
	medians = malloc(sizeof(int) * n_medians);
	if (!medians)
		exit(EXIT_FAILURE);
	while (i < n_medians)
	{
		medians[i] = get_median(arr + i * 5, 5);
		i++;
	}
	median = mofm(medians, n_medians);
	free(medians);
	return (median);
}

int	partition(int *arr, int left, int right)
{
	int	piv;
	int	temp;
	int	i;
	int	j;

	piv = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < piv)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = piv;
	arr[right] = temp;
	return (i + 1);
}

/*
** put the pivot element in its right place
** if k is 
*/
int	quick_select(int *arr, int left, int right, int k)
{
	int	p;

	if (k > 0 && k <= right - left + 1)
	{
		p = partition(arr, left, right);
		if (p - left == k - 1)
			return (arr[p]);
		if (p - left > k - 1)
			return (quick_select(arr, left, p - 1, k));
		return (quick_select(arr, p + 1, right, k - p + left - 1));
	}
	return (0);
}

int	get_kth_smallest(t_stack *stack, int k)
{
	int	*arr;
	int	target;

	arr = arrayify(stack);
	if (!arr)
		exit(EXIT_FAILURE);
	target = quick_select(arr, 0, ft_stacksize(stack), k);
	free(arr);
	return (target);
}