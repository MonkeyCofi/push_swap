/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/04 03:04:57 by uwubuntu         ###   ########.fr       */
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
	if (!is_sorted(stack_a))
	{
		if (ft_stacksize(stack_a) == 3)
			sort_small_stack(&stack_a);
		else
			sort_medium_stack(&stack_a, &stack_b);
	}
	print_stacks(stack_a, stack_b);
	ft_printf("stack is sorted\n");
	clear_stack(&stack_a);
	exit(EXIT_SUCCESS);
	(void)argc;
}
