/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:50 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
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

void	sort_small_stack(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3 && !is_sorted(*a))
	{
		if ((*a)->value == get_smallest(*a))
			push(b, a, 'b');
		else if (get_node(*a, get_smallest(*a))->pos <= (ft_stacksize(*a) / 2))
			rotate(a, 'a', 0);
		else
			reverse_rotate(a, 'a', 0);
	}
	sort_small_stack(a);
	while (!is_empty(*b))
		push(a, b, 'b');
}

int	chunk_divider(int stack_size)
{
	int	chunks;

	chunks = 2;
	while (stack_size / chunks >= 50)
		chunks *= 2;
	if (chunks > 8)
		chunks = 8;
	return (chunks);
}

// void	push_chunk(t_stack **a, t_stack **b)
// {
// 	t_chunk	c;
// 	int		chunk_nums;

// 	chunk_nums = chunk_divider(ft_stacksize(*a));
// 	fill_chunk(*a, &c, chunk_nums);
// 	while (ft_stacksize(*a) > c.remaining)
// 	{
// 		if ((*a)->value <= c.pivot)
// 			push(b, a, 'b');
// 		else if ((*a)->value > c.pivot && (*a)->pos < c.sub_median)
// 			rotate(a, 'a', 0);
// 		else
// 			reverse_rotate(a, 'a', 0);
// 	}
// }

void	push_chunk(t_stack **a, t_stack **b)
{
	t_chunk	c;
	int		chunk_nums;

	chunk_nums = chunk_divider(ft_stacksize(*a));
	fill_chunk(*a, &c, chunk_nums);
	while (ft_stacksize(*a) > c.remaining)
	{
		if ((*a)->value <= c.pivot)
			push(b, a, 'b');
		else if ((*a)->value > c.pivot && (*a)->pos < c.sub_median)
			rotate(a, 'a', 0);
		else
			reverse_rotate(a, 'a', 0);
	}
}

/*
** push elements from smallest to largest
** so that when pushed back, they will be sorted
** three largest elements will stay in stack a
** and will be sorted using 3 sort
*/
void	sort_chunk(t_stack **a, t_stack **b)
{
	int	smallest;

	smallest = get_smallest(*a);
	while (ft_stacksize(*a) > 3)
	{
		if ((*a)->value == smallest)
		{
			push(b, a, 'b');
			smallest = get_smallest(*a);
		}
		else if (get_node(*a, smallest)->pos < ft_stacksize(*a) / 2)
			rotate(a, 'a', 0);
		else
			reverse_rotate(a, 'a', 0);
	}
	sort_small_stack(a);
}

/*
** divide the stack into sub-chunks
** get the value at the ending position of each chunk
** go through the whole stack to count the amount of values that are lesser than the pivot value
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	// push a chunk into stack b
	while (i < chunk_divider(ft_stacksize(*a)))
	{
		push_chunk(a, b);
		i++;
	}
	// place the smallest value in a on top and the largest value in b on top
	// while ((*a)->value != get_smallest(*a))
	// {
	// 	if ((*a)->next->value == get_smallest(*a))
	// 	{
	// 		if ((*b)->next->value == get_largest(*b))
	// 			ss(a, b);
	// 		else
	// 			swap(a, 'a', 0);
	// 	}
	// 	else if (get_node(*a, get_smallest(*a))->pos < ft_stacksize(*a) / 2 + (ft_stacksize(*a) % 2))
	// 	{
	// 		if ((*b)->value != get_largest(*b))
	// 			rr(a, b);
	// 		else
	// 			rotate(a, 'a', 0);
	// 	}
	// 	else if (get_node(*a, get_smallest(*a))->pos < ft_stacksize(*a) / 2 + (ft_stacksize(*a) % 2))
	// 	{
	// 		if ((*b)->value != get_largest(*b))
	// 			rrr(a, b);
	// 		else
	// 			reverse_rotate(a, 'a', 0);
	// 	}
	// }
	sort_chunk(a, b);
	push_largest(a, b);
}

void	push_largest(t_stack **a, t_stack **b)
{
	int	largest_b;

	largest_b = get_largest(*b);
	while (!is_empty(*b))
	{
		if ((*b)->value == largest_b)
		{
			push(a, b, 'a');
			largest_b = get_largest(*b);
		}
		else
		{
			if (get_node(*b, largest_b)->pos <= ft_stacksize(*b) / 2)
				rotate(b, 'b', 0);
			else if (get_node(*b, largest_b)->pos > ft_stacksize(*b) / 2)
				reverse_rotate(b, 'b', 0);
		}
	}
}
