/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/08 02:04:00 by uwubuntu         ###   ########.fr       */
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
			// sort_large(&stack_a, &stack_b);
			// sort_5(&stack_a, &stack_b);
			sort_stack(&stack_a, &stack_b);
	}
	// ft_printf("\n\n");
	print_stacks(stack_a, stack_b);
	// ft_printf("%d\n", ft_stacksize(stack_b));
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	exit(EXIT_SUCCESS);
	(void)argc;
}
