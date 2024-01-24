/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/24 10:19:51 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int	temp;

	if (ft_lstsize((*stack)) < 1)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
/*
* take first element from the top of stack2 and push it to top of stack1
* do nothing if stack2 is empty
* use lst_addfront to add the first node of stack2 to stack1
* use lst_delone to remove from stack2
*/
void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*new;
	
	if (!ft_lstsize(*stack2))
		return ;
	new = ft_lstnew((*stack2)->value);
	ft_lstadd_front(stack1, new);
	delete_node(stack2, (*stack2));
}

/*
* create a node that points to top of stack
* while the node is not null
* hehe reverse_rotate
* 
*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*top;

	iter = (*stack);
	top = iter;
	while (iter->next->next)
		iter = iter->next;
	(*stack) = iter->next;
	(*stack)->next = top;
	iter->next = NULL;
}


/*
 * set a node equal to the top of the stack
 * set another node to be the last node of the stack
 * set iter as top's new next
 * set the stack to equal to stack->next
 * */
void	rotate(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*top;

	iter = (*stack);
	top = iter;
	while (iter->next)
		iter = iter->next;
	(*stack) = (*stack)->next;
	iter->next = top;
	top->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
