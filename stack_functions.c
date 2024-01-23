/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:09:42 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/23 18:38:32 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_lst(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->value = 0;
	return (new);
}

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

void	ft_lst_addback(t_stack **stack, t_stack *node)
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

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
	ft_printf("-");
}

/*
* traverse through the list until del value is found within node
* use another node and assign it to the node before del node
* set temp node to del node
* set del node to del node's next
* free temp_node
* set prev node's next to current node
*/
void	delete_node(t_stack **stack, t_stack *del)
{
	t_stack	*prev;
	t_stack	*iter;
	t_stack	*tmp;

	iter = (*stack);
	while (iter->next)
	{
		prev = iter;
		iter = iter->next;
		if (iter->value == del->value)
		{
			tmp = iter;
			iter = iter->next;
			free(tmp);
			prev->next = iter;
			return ;
		}
	}
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	while(stack1)
	{
		if (stack2)
		{
			ft_printf("%-15d%d\n", stack1->value, stack2->value);
			stack2 = stack2->next;
		}
		else
			ft_printf("%-15d\n", stack1->value);
		stack1 = stack1->next;
	}
	ft_printf("%-15c%c\n", '-', '-');
	ft_printf("%-15c%c", 'a', 'b');
}
