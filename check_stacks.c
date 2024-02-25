/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:14:23 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/25 13:56:23 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* if return is -1, stack is NULL
* if return is 1, stack is sorted
* if return is 0, stack is not sorted
*/
int	is_sorted(t_stack *stack)
{
	t_stack	*next;

	if (ft_stacksize(stack) < 2)
		return (1);
	next = stack->next;
	while (stack->next && stack->value < next->value)
	{
		stack = stack->next;
		next = stack->next;
	}
	if (next == NULL)
		return (1);
	return (0);
}

int	get_smallest(t_stack *stack)
{
	int	smallest_val;

	if (!stack)
		return (0);
	smallest_val = stack->value;
	while (stack)
	{
		if (stack->value < smallest_val)
			smallest_val = stack->value;
		stack = stack->next;
	}
	return (smallest_val);
}

int	get_largest(t_stack *stack)
{
	int	largest;

	if (!stack)
		return (0);
	largest = stack->value;
	while (stack)
	{
		if (stack->value > largest)
			largest = stack->value;
		stack = stack->next;
	}
	return (largest);
}

int	get_larger_value(t_stack *stack, int value)
{
	int	target;

	target = get_largest(stack);
	while (stack)
	{
		if (stack->value > value && stack->value < target)
			target = stack->value;
		stack = stack->next;
	}
	return (target);
}

t_stack	*search_node(t_stack *stack, int number)
{
	while (stack)
	{
		if (stack->value == number)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
