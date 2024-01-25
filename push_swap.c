/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/25 15:49:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	add_to_stack(&stack_a, argv);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	print_stacks(stack_a, stack_b);
	clear_stack(&stack_a);
	(void)argc;
}
