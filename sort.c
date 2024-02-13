/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/10 22:12:09 by pipolint         ###   ########.fr       */
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
	int	smallest;

	smallest = get_smallest(*a);
	while (ft_stacksize(*a) > 3 && !is_sorted(*a))
	{
		if ((*a)->value == smallest)
		{
			push(b, a, 'b');
			smallest = get_smallest(*a);
		}
		else if ((*a)->next->value == smallest && get_larger_value(*a, smallest))
			swap(a, 'a', 0);
		else if (get_node(*a, smallest)->pos <= (ft_stacksize(*a) / 2))
			rotate(a, 'a', 0);
		else
			reverse_rotate(a, 'a', 0);
	}
	sort_three(a);
	while (!is_empty(*b))
		push(a, b, 'a');
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
	int	size;

	smallest = get_smallest(*a);
	size = ft_stacksize(*a);
	while (ft_stacksize(*a) > 3)
	{
		if ((*a)->value == smallest)
		{
			push(b, a, 'b');
			smallest = get_smallest(*a);
		}
		else if ((*a)->next->value == smallest && get_lastnode(*a)->value == get_larger_value(*a, smallest))
			swap(a, 'a', 0);
		else if (get_node(*a, smallest)->pos <= ft_stacksize(*a) / 2)
			rotate(a, 'a', 0);
		else
			reverse_rotate(a, 'a', 0);
	}
	sort_three(a);
	while (ft_stacksize(*a) < size)
		push(a, b, 'a');
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

void	push_chunk(t_stack **a, t_stack **b, int chunks)
{
	t_chunk	c;
	int		val_dist;

	fill_chunk(*a, &c, chunks);
	ft_printf("Sub-median: %d\n", c.sub_median);
	val_dist = closest(*a, c.pivot);
	while (ft_stacksize(*a) > c.remaining)
	{
		if ((*a)->value <= c.pivot || get_lastnode(*a)->value <= c.pivot)
		{
			if ((get_lastnode(*a)->value <= c.pivot && (*a)->value > c.pivot) || val_dist > c.median)
				reverse_rotate(a, 'a', 0);
			push(b, a, 'b');
		}
		else if ((*a)->value > c.pivot)
		{
			if ((*b) && (*b)->value <= c.sub_median)
				rr(a, b);
			else
			{
				rotate(a, 'a', 0);
			}
		}
		// if ((*a)->value <= c.pivot)
		// {
		// 	push(b, a, 'b');
		// 	val_dist = closest(*a, c.pivot);
		// }
		// else if ((*b) && (*b)->value <= c.sub_median && (*a)->value > c.pivot && val_dist <= c.median)
		// {
		// 	rr(a, b);
		// }
		// else if ((*a)->next->value <= c.pivot && get_lastnode(*a)->value <= c.pivot)
		// 	swap(a, 'a', 0);
		// else if ((*a)->value > c.pivot && val_dist <= c.median)
		// {
		// 	rotate(a, 'a', 0);
		// }
		// else
		// 	reverse_rotate(a, 'a', 0);
	}
}

// void	push_chunk(t_stack **a, t_stack **b, int chunks)
// {
// 	t_chunk	chunk;
// 	int		val_dist;
//
// 	fill_chunk(*a, &chunk, chunks);
// 	val_dist = closest(*a, chunk.pivot);
// }

void	sort_stack(t_stack **a, t_stack **b)
{
	int	chunks;

	chunks = chunk_divider(ft_stacksize(*a));
	while (chunks > 1)
	{
		push_chunk(a, b, chunks--);
	}
	push_chunk(a, b, 2);
	sort_chunk(a, b);
	// print_stacks(*a, *b);
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
			if ((*b)->next->value == largest_b && get_lastnode(*b)->value == get_smaller_value(*b, largest_b))
				swap(b, 'b', 0);
			else if (get_node(*b, largest_b)->pos <= ft_stacksize(*b) / 2)
				rotate(b, 'b', 0);
			else if (get_node(*b, largest_b)->pos > ft_stacksize(*b) / 2)
				reverse_rotate(b, 'b', 0);
		}
	}
}

/*
 * top and bottom of stack a will contain the largest values
 * top of stack b will contain upper bounds of the middle values
 * bottom of stack b will contain lower bounds of middle values
 * and the smallest values
 * */

/*
 * push all values from middle chunks first
 * */
// void	push_back(t_stack **a, t_stack **b, int start_pos, int end_pos)
// {
	// int	val1;
	// int	val2;

	// val1 = get_kth_snallest(*b, start_pos);
	// val2 = get_kth_snallest(*b, end_pos);
// 	while ()
// }
