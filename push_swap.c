/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/13 18:57:19 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		temp_printflag;

	temp_printflag = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_strncmp(argv[argc - 1], "print", ft_strlen("print")))
	{
		temp_printflag = 1;
		argv[argc - 1] = 0;
	}
	add_to_stack(&stack_a, argv);
	if (!is_sorted(stack_a))
	{
		if (ft_stacksize(stack_a) == 3)
			sort_three(&stack_a);
		else if (ft_stacksize(stack_a) <= 10)
			sort_small_stack(&stack_a, &stack_b);
		else
			sort_stack(&stack_a, &stack_b);
	}
	if (temp_printflag == 1)
		print_stacks(stack_a, stack_b);
	//if (is_sorted(stack_a))
	//	ft_printf("Stack is sorted\n");
	//else
	//	ft_printf("Stack is not sorted\n");
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	exit(EXIT_SUCCESS);
	(void)argc;
}
