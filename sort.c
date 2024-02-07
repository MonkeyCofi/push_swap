/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/07 18:25:21 by uwubuntu         ###   ########.fr       */
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
// 		move_stack(stack_a, largest, smallest);
// 	}
// }

// void	move_stack(t_stack **stack, int largest, int smallest)
// {
// 	if (is_sorted(*stack))
// 		return ;
// 	if ((*stack)->value != largest && (*stack)->value > (*stack)->next->value && (*stack)->value != get_largest(*stack))
// 		swap(stack, 'a', 0);
// 	else if ((*stack)->value > (*stack)->next->value && (*stack)->next->value != smallest)
// 		reverse_rotate(stack, 'a', 0);
// 	else
// 		rotate(stack, 'a', 0);
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

/*
** divide the size of the list by half
** anything above the halfpoint would need to rotate to get to the top in the shortest amount of moves
** anything below the halfpoint would need to reverse rotate to get to the top in the shortest amount of moves
*/
// void	sort_stack(t_stack **a, t_stack **b)
// {
// 	int	median;
// 	int	midpoint;

// 	median = get_kth_smallest(*a, ft_stacksize(*a) / 2);
// 	midpoint = ft_stacksize(*a) / 2;
	
// }

// void	sort_5(t_stack **a, t_stack **b)
// {
// 	while (ft_stacksize(*a) > 3 && !is_sorted(*a))
// 	{
// 		if ((*a)->value == get_smallest(*a))
// 			push(b, a, 'b');
// 		else if (get_node(*a, get_smallest(*a))->pos < (ft_stacksize(*a) / 2) + (ft_stacksize(*a) % 2))
// 			rotate(a, 'a', 0);
// 		else
// 			reverse_rotate(a, 'a', 0);
// 	}
// 	sort_small_stack(a);
// 	while (!is_empty(*b))
// 		push(a, b, 'b');
// }

int	chunk_divider(int stack_size)
{
	int	chunks;

	chunks = 4;
	while (stack_size / chunks > 100)
		chunks *= 2;
	return (chunks);
}

void	push_chunk(t_stack **a, t_stack **b)
{
	t_chunk	c;
	int		chunk_nums;

	chunk_nums = chunk_divider(ft_stacksize(*a));
	fill_chunk(*a, &c, chunk_nums);
	ft_printf("%d > %d\n", ft_stacksize(*a), c.remaining);
	while (ft_stacksize(*a) > c.remaining)
	{
		if ((*a)->value <= c.pivot)
			push(b, a, 'b');
		else if ((*a)->value > c.pivot && (*a)->pos < c.sub_median)
			rotate(a, 'a', 0);
		else
			reverse_rotate(a, 'a', 0);
	}
	ft_printf("%d\n", c.pivot);
	(void)b;
}

/*
** divide the stack into sub-chunks
** get the value at the ending position of each chunk
** go through the whole stack to count the amount of values that are lesser than the pivot value
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	push_chunk(a, b);
}
