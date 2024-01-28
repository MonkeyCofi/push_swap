/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/28 19:18:32 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack **stack_a)
{
	int		smallest;
	int		largest;

	smallest = get_smallest(*stack_a);
	largest = get_largest(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->value != largest && (*stack_a)->value != smallest)
		{
			if ((*stack_a)->next->value == largest)
				reverse_rotate(stack_a, 'a', 0);
			else
				swap(stack_a, 'a', 0);
		}
		else if ((*stack_a)->value == largest)
			rotate(stack_a, 'a', 0);
		else if ((*stack_a)->value == smallest)
			rotate(stack_a, 'a', 0);
	}
}

void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	largest;

	smallest = get_smallest((*stack_a));
	largest = get_largest((*stack_b));
	while (!is_sorted(*stack_a))
	{
		if (is_empty(*stack_b))
		{
			push(stack_b, stack_a, 'a');
			push(stack_b, stack_a, 'a');
		}
		sort_small_stack(stack_a);
	}
	(void)smallest;
	(void)largest;
	(void)stack_a, (void)stack_b;
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*trav;
	int		smallest;
	int		largest;

	trav = (*stack_a);
	smallest = get_smallest(*stack_a);
	largest = get_largest(*stack_a);
	while (trav && !is_sorted(*stack_a))
	{
		return ;
		//while ((*stack_a)->value < (*stack_b)->value)
		//{
		//	push(stack_b, stack_a, 'b');
		//}
		//trav = trav->next;
	}
	(void)stack_b;
	(void)smallest, (void)largest;
}
