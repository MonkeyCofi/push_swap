/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:43:04 by uwubuntu          #+#    #+#             */
/*   Updated: 2024/02/09 11:54:11 by uwubuntu         ###   ########.fr       */
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

int	closest(t_stack *stack, int value)
{
	int	stack_size;
	int	distance;

	stack_size = ft_stacksize(stack);
	distance = 0;
	while (stack)
	{
		if (stack->value <= value)
			break ;
		distance++;
		stack = stack->next;
	}
	if (distance > stack_size / 2)
		return (stack_size - distance);
	return (distance);
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
	val_dist = closest(*a, c.pivot);
	while (ft_stacksize(*a) > c.remaining)
	{
		if ((*a)->value <= c.pivot || get_lastnode(*a)->value <= c.pivot)
		{
			// if ((get_lastnode(*a)->value <= c.pivot && (*a)->value > c.pivot) || val_dist > c.median)
			if ((get_lastnode(*a)->value <= c.pivot && (*a)->value > c.pivot))
				reverse_rotate(a, 'a', 0);
			val_dist = closest(*a, c.pivot);
			push(b, a, 'b');
		}
		else if ((*a)->value > c.pivot)
		{
			if ((*b) && (*b)->value <= c.sub_median)
				rr(a, b);
			else if (val_dist > c.median)
				reverse_rotate(a, 'a', 0);
			else
				rotate(a, 'a', 0);
		}
	}
}
