/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/26 20:09:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_stack *stack)
{
	t_stack	*trav;
	int		smallest_val;

	trav = stack;
	smallest_val = stack->value;
	while (trav)
	{
		if (smallest_val > trav->value)
			smallest_val = trav->value;
		trav = trav->next;
	}
	return (smallest_val);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*trav;
	int		moves;

	trav = (*stack_a);
	moves = 0;
	if (!(*stack_b))
	{
		push(stack_b, stack_a);
		moves++;
	}
	while (trav)
	{
		while ((*stack_a)->value < (*stack_b)->value)
		{
			push(stack_b, stack_a);
			moves++;
		}
		
		trav = trav->next;
	}
	ft_printf("It took %d moves\n", moves);
}
