/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:16:34 by uwubuntu          #+#    #+#             */
/*   Updated: 2024/02/25 14:06:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'a', 1);
	rotate(stack_b, 'b', 1);
	update_index(stack_a, stack_b, 1);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'a', 1);
	reverse_rotate(stack_b, 'b', 1);
	update_index(stack_a, stack_b, 1);
	ft_putendl_fd("rrr", 1);
}
