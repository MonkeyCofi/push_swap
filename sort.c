/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/01 16:50:19 by pipolint         ###   ########.fr       */
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

//void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b)
//{
//	int	smallest;
//	int	largest;

//	smallest = get_smallest((*stack_a));
//	largest = get_largest((*stack_a));
//	while (!is_sorted(*stack_a) || !is_empty(*stack_b))
//	{
//		if (is_empty(*stack_b))
//		{
//			push(stack_b, stack_a, 'b');
//			push(stack_b, stack_a, 'b');
//		}
//		if (ft_stacksize(*stack_a) == 3)
//			sort_small_stack(stack_a);
//		if ((*stack_b)->value == largest && (*stack_b))
//		{
//			push(stack_a, stack_b, 'a');
//			rotate(stack_a, 'a', 0);
//		}
//		else
//			push(stack_a, stack_b, 'a');
//		if ((*stack_a)->value != largest && (*stack_a)->value > (*stack_a)->next->value)
//			swap(stack_a, 'a', 0);
//		else if ((*stack_a)->value > (*stack_a)->next->value)
//			reverse_rotate(stack_a, 'a', 0);
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

void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	largest;

	smallest = get_smallest((*stack_a));
	largest = get_largest((*stack_a));
	if (is_empty(*stack_b))
	{
		push(stack_b, stack_a, 'b');
		push(stack_b, stack_a, 'b');
	}
	sort_small_stack(stack_a);
	while (!is_sorted(*stack_a) || !is_empty(*stack_b))
	{
		push(stack_a, stack_b, 'a');
		move_stack(stack_a, largest, smallest);
	}
}

void	move_stack(t_stack **stack, int largest, int smallest)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value != largest && (*stack)->value > (*stack)->next->value)
		swap(stack, 'a', 0);
	else if ((*stack)->value > (*stack)->next->value)
		reverse_rotate(stack, 'a', 0);
	else
		rotate(stack, 'a', 0);
	if ((*stack)->value == largest && (*stack)->next->value == smallest)
		rotate(stack, 'a', 0);
}
