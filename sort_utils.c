/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:43:04 by uwubuntu          #+#    #+#             */
/*   Updated: 2024/02/07 11:01:56 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_largest(t_stack *stack, int value)
{
	int	largest;

	largest = get_largest(stack);
	while (stack)
	{
		if (stack->value > value && stack->value < largest)
			largest = stack->value;	// if the value is greater than value but lesser than largest
		stack = stack->next;
	}
	return (largest);
}

void	update_index(t_stack **a, t_stack **b, int need_b)
{
	t_stack	*trav;
	int		index;

	trav = (*a);
	index = 0;
	while (trav)
	{
		trav->pos = index;
		index++;
		trav = trav->next;
	}
	if (need_b)
	{
		index = 0;
		trav = (*b);
		while (trav)
		{
			trav->pos = index;
			index++;
			trav = trav->next;
		}
	}
}
