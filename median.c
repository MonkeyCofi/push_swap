/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/30 20:36:37 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array(t_stack *stack)
{
	int	*array;
	int	index;

	array = malloc((ft_stacksize(stack)) * sizeof(int));
	index = 0;
	if (!array)
		exit(EXIT_FAILURE);
	while (stack)
	{
		array[index++] = stack->value;
		stack = stack->next;
	}
	return (array);
}

int	nth_smallest(int *array, int index)
{
	
}
/*
* 
*/
int	select(int *array, int *left, int *right, int index)
{
	
}
