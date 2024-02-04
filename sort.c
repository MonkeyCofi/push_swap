/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/04 12:05:50 by uwubuntu         ###   ########.fr       */
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

// void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	smallest;
// 	int	largest;
// 	int	second_largest;

// 	smallest = get_smallest((*stack_a));
// 	largest = get_largest((*stack_a));
// 	second_largest = get_second_largest(*stack_a, largest, smallest);
// 	if (is_empty(*stack_b))
// 	{
// 		push(stack_b, stack_a, 'b');
// 		push(stack_b, stack_a, 'b');
// 	}
// 	sort_small_stack(stack_a);
// 	while (!is_sorted(*stack_a) || !is_empty(*stack_b))
// 	{
// 		push(stack_a, stack_b, 'a');
// 		if ((*stack_b) && (*stack_b)->value == second_largest && (*stack_a)->value == largest)
// 			push(stack_a, stack_b, 'a');
// 		move_stack(stack_a, largest, second_largest, smallest);
// 	}
// }

// void	move_stack(t_stack **stack, int largest, int smallest)
// {
// 	if (is_sorted(*stack))
// 		return ;
// 	if ((*stack)->value != largest && (*stack)->value > (*stack)->next->value && (*stack)->value != get_largest(*stack))
// 		swap(stack, 'a', 0);
// 	else if (ft_stacksize(find_node(*stack, smallest)) <= 2)
// 		reverse_rotate(stack, 'a', 0);
// 	else if ((*stack)->value > (*stack)->next->value && (*stack)->next->value != smallest)
// 	{
// 		reverse_rotate(stack, 'a', 0);
// 	}
// 	else
// 	{
// 		rotate(stack, 'a', 0);
// 	}
// 	if ((*stack)->value == largest && (*stack)->next->value == smallest)
// 		rotate(stack, 'a', 0);
// }

// void	move_stack(t_stack **a, int largest, int second_largest, int smallest)
// {
// 	if (is_sorted(*a))
// 		return ;
// 	if ((*a)->value == second_largest && (*a)->next->value == largest)
// 	{
// 		rotate(a, 'a', 0);
// 		rotate(a, 'a', 0);
// 	}
// 	if ((*a)->value == get_largest(*a))
// 		rotate(a, 'a', 0);
// 	else if ((*a)->value != largest && (*a)->value != smallest)
// 	{
// 		if ((*a)->value > (*a)->next->value && (*a)->value != second_largest)
// 			swap(a, 'a', 0);
// 		else
// 			reverse_rotate(a, 'a', 0);
// 	}
// 	else
// 		reverse_rotate(a, 'a', 0);

// }

void	sort_medium_stack(t_stack **a, t_stack **b)
{
	int	smallest;
	int	largest;

	largest = get_largest(*a);
	smallest = get_smallest(*a);
	push(b, a, 'b');
	push(b, a, 'b');
	sort_small_stack(a);
	while (!is_sorted(*a) || !is_empty(*b))
	{
		push(a, b, 'a');
	}
}


void	move_stack(t_stack **s, int largest, int smallest)
{
	if (is_sorted(*s))
		return ;
	
}
