/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/26 19:29:09 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* if 
*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*trav;

	trav = (*stack_a);
	if (!(*stack_b))
		push(stack_b, stack_a);
	print_stacks(*stack_a, *stack_b);
	while (trav)
	{
		return ;
	}
}
