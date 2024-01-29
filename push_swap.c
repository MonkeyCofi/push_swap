/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/29 16:30:59 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	add_to_stack(&stack_a, argv);
	if (is_sorted(stack_a))
	{
		clear_stack(&stack_a);
		exit(EXIT_SUCCESS);
	}
	//if (ft_stacksize(stack_a) == 3)
	//{
		sort_small_stack(&stack_a);
	//	print_stacks(stack_a, stack_b);
	//	exit(EXIT_SUCCESS);
	//}
	//sort_medium_stack(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	clear_stack(&stack_a);
	(void)argc;
}
