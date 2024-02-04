/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/05 02:41:22 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

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
