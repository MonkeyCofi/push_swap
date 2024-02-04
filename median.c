/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/04 14:02:57 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dup stack elements into array
static int	*arrayify(t_stack *stack)
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
	return (arr[n / 2 - 1] + arr[n / 2] / 2);
}

