/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/27 19:14:22 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*trav;
	int		smallest;
	int		largest;

	trav = (*stack_a);
	smallest = get_smallest(*stack_a);
	largest = get_largest(*stack_a);
	if (!(*stack_b))
	{
		push(stack_b, stack_a);
	}
	while (trav)
	{
		while ((*stack_a)->value < (*stack_b)->value)
		{
			push(stack_b, stack_a);
		}
		
		trav = trav->next;
	}
}
