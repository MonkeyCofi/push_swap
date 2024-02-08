/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/08 13:58:43 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char stack_let, int ss)
{
	int	temp;

	if (ft_stacksize((*stack)) < 2)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	if (!ss)
		update_index(stack, NULL, 0);
	if (stack_let == 'a' && !ss)
		ft_putendl_fd("sa", 1);
	else if (stack_let == 'b' && !ss)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 'a', 1);
	swap(stack_b, 'a', 1);
	update_index(stack_a, stack_b, 1);
	ft_putendl_fd("ss", 1);
}

/*
* take first element from the top of stack2 and push it to top of stack1
* do nothing if stack2 is empty
* use lst_addfront to add the first node of stack2 to stack1
* use lst_delone to remove from stack2
*/
void	push(t_stack **stack1, t_stack **stack2, char stack)
{
	t_stack	*new;

	if (is_empty((*stack2)))
		return ;
	new = ft_newnode((*stack2)->value, 0);
	// if (!(*stack1))
	// {
	// 	(*stack1) = new;
	// 	return ;
	// }
	ft_stackadd_top(stack1, new);
	delete_node(stack2, (*stack2));
	update_index(stack1, stack2, 1);
	if (stack == 'a')
		ft_putendl_fd("pa", 1);
	else
		ft_putendl_fd("pb", 1);
}

/*
* create a node that points to top of stack
* create another node to iterate through the stack
* iterate up until the second last node and set the iter
*	node to equal to that node
* set stack to iter's next node (the last node of the stack)
* set stack's next node to top
* set iter's next node to NULL
*/
void	reverse_rotate(t_stack **stack, char stack_let, int rrr)
{
	t_stack	*iter;
	t_stack	*top;

	if (is_empty(*stack))
		return ;
	iter = (*stack);
	top = iter;
	while (iter->next->next)
		iter = iter->next;
	(*stack) = iter->next;
	(*stack)->next = top;
	iter->next = NULL;
	if (!rrr)
		update_index(stack, NULL, 0);
	if (stack_let == 'a' && !rrr)
		ft_putendl_fd("rra", 1);
	else if (stack_let == 'b' && !rrr)
		ft_putendl_fd("rrb", 1);
}

/*
 * set a node equal to the top of the stack
 * set another node to be the last node of the stack
 * set iter as top's new next
 * set the stack to equal to stack->next
 * */
// void	rotate(t_stack **stack, char stack_let, int rr)
// {
// 	t_stack	*iter;
// 	t_stack	*top;

// 	if (is_empty(*stack))
// 		return ;
// 	iter = (*stack);
// 	top = iter;
// 	while (iter->next)
// 		iter = iter->next;
// 	(*stack) = (*stack)->next;
// 	iter->next = top;
// 	top->next = NULL;
// 	if (!rr)
// 		update_index(stack, NULL, 0);
// 	if (stack_let == 'a' && !rr)
// 		ft_putendl_fd("ra", 1);
// 	else if (stack_let == 'b' && !rr)
// 		ft_putendl_fd("rb", 1);
// }

void	rotate(t_stack **stack, char stack_let, int rr)
{
	t_stack	*top;

	top = pop(stack);
	get_lastnode(*stack)->next = top;
	if (!rr)
		update_index(stack, NULL, 0);
	if (stack_let == 'a' && !rr)
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
}
