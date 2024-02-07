/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/07 18:25:12 by uwubuntu         ###   ########.fr       */
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
	target = quick_select(arr, 0, ft_stacksize(stack) - 1, k);
	free(arr);
	return (target);
}

/*
** stack will be divided into chunks of 4
** chunks of eight if the stack size is greater than 250
** set the sub_pivot point ot be the pivot point of each sub chunk
*/
void	fill_chunk(t_stack *a, t_chunk *c, int chunk_num)
{
	int	chunk_end;
	int	chunk_size;

	chunk_end = ft_stacksize(a) / chunk_num;
	c->pivot = get_kth_smallest(a, chunk_end);
	c->sub_median = chunk_end / 2;
	c->remaining = 0;
	while (a)
	{
		if (a->value > c->pivot)
			c->remaining++;
		a = a->next;
	}
	(void)chunk_size;
}
