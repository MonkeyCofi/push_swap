/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/30 16:43:33 by pipolint         ###   ########.fr       */
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
			reverse_rotate(stack_a, 'a', 0);
	}
}

void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	largest;

	smallest = get_smallest((*stack_a));
	largest = get_largest((*stack_a));
	while (!is_sorted(*stack_a) || !is_empty(*stack_b))
	{
		if (is_empty(*stack_b))
		{
			push(stack_b, stack_a, 'b');
			push(stack_b, stack_a, 'b');
		}
		if (ft_stacksize(*stack_a) == 3)
			sort_small_stack(stack_a);
		if ((*stack_b)->value == largest && (*stack_b))
		{
			push(stack_a, stack_b, 'a');
			rotate(stack_a, 'a', 0);
		}
		else if (((*stack_b)->value == smallest || (*stack_b)->value > (*stack_a)->value) && (*stack_b))
		{
			push(stack_a, stack_b, 'a');
		}
		else
		{
			push(stack_a, stack_b, 'a');
			swap(stack_a, 'a', 0);
		}
	}
}

//void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b)
//{
//	int	smallest;
//	int	largest;

//	smallest = get_smallest((*stack_a));
//	largest = get_largest((*stack_a));
//	while (!is_sorted(*stack_a))
//	{
//		if (is_empty(*stack_b) && ft_stacksize(*stack_a) > 3)
//		{
//			push(stack_b, stack_a, 'b');
//			push(stack_b, stack_a, 'b');
//		}
//		if (ft_stacksize(*stack_a) == 3)
//		{
//			sort_small_stack(stack_a);
//			if (is_sorted(*stack_a) && is_empty(*stack_b))
//				return ;
//		}
//		if (((*stack_b)->value != largest && (*stack_b)->value != smallest) || ft_stacksize(*stack_b) == 1)
//		{
//			if ((*stack_b)->value > (*stack_a)->next->value && (*stack_b)->value < get_lastnode(*stack_a)->value)
//				reverse_rotate(stack_a, 'a', 0);
//			else if ((*stack_b)->value < (*stack_a)->value)
//				rotate(stack_a, 'a', 0);
//		}
//		push(stack_a, stack_b, 'a');
//	}
//}

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

//void	push_last(t_stack **stack_a, t_stack **stack_b)
//{
//	if (!is_empty(*stack_b))
//		push(stack_a, stack_b, 'b');
//	if (is_sorted((*stack_a)->next))
//		rotate(stack_a, 'a', 0);
//}