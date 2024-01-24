/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/23 21:05:29 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	init_stack(t_stack *stack)
//{
	
//}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	add_to_stack(&stack_a, argv);
	print_stacks(stack_a, stack_b);
	ft_printf("\n");
	add_to_stack(&stack_b, argv);	
	print_stacks(stack_a, stack_b);
	ft_printf("\n");
	rr(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	(void)argc;
}
