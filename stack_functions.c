/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:09:42 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/26 11:39:11 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newnode(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->value = content;
	return (node);
}

void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*iter;

	if (!node)
	{
		perror(NULL);
		return ;
	}
	if (!(*stack))
		(*stack) = node;
	else
	{
		iter = (*stack);
		while (iter->next)
			iter = iter->next;
		iter->next = node;
	}
}

int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	while (stack1 || stack2)
	{
		if (stack1)
		{
			if (!stack2)
				ft_printf("%d\n", stack1->value);
			else
				ft_printf("%-15d", stack1->value);;
			stack1 = stack1->next;
		}
		else
			ft_printf("%-15c", ' ');
		if (stack2)
		{
			ft_printf("%d\n", stack2->value);
			stack2 = stack2->next;
		}
	}
	ft_printf("%-15c%c\n", '-', '-');
	ft_printf("%-15c%c", 'a', 'b');
	ft_printf("\n\n");
}
