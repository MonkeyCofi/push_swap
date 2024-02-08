/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:45 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/08 13:54:21 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_top(t_stack **stack, t_stack *node)
{
	node->next = (*stack);
	(*stack) = node;
}

void	clear_stack(t_stack **stack)
{
	if (is_empty(*stack))
		return ;
	while ((*stack))
		delete_node(stack, (*stack));
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

	if (del->value == (*stack)->value)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
		return ;
	}
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

t_stack	*pop(t_stack **stack)
{
	t_stack	*node;

	node = ft_newnode((*stack)->value, 0);
	if (!node)
		return (NULL);
	delete_node(stack, (*stack));
	return (node);
}

int	is_empty(t_stack *stack)
{
	if (stack)
		return (0);
	return (1);
	// if (ft_stacksize(stack) < 1)
	// 	return (1);
	// return (0);
}
