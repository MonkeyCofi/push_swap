/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:57 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/07 03:12:17 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				pos;
	int				value;
}	t_stack;

int		count_arguments(char **argv);
void	add_to_stack(t_stack **stack, char **argv);

// Stack functions
//t_stack	*pop(t_stack **stack);
int		is_empty(t_stack *stack);
t_stack	*new_lst(void);
t_stack	*ft_newnode(int content, int index);
int		ft_stacksize(t_stack *lst);
void	ft_stackadd_top(t_stack **stack, t_stack *node);
void	ft_stackadd_back(t_stack **stack, t_stack *node);
void	print_stacks(t_stack *stack1, t_stack *stack2);
void	delete_node(t_stack **stack, t_stack *del);
void	clear_stack(t_stack **stack);
t_stack	*get_lastnode(t_stack *stack);
t_stack	*get_node(t_stack *node, int value);

// moves
void	push(t_stack **stack1, t_stack **stack2, char stack);
void	swap(t_stack **stack, char stack_let, int ss);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack, char stack_let, int rr);
void	reverse_rotate(t_stack **stack, char stack_let, int rrr);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// sort
void	sort_small_stack(t_stack **stack_a);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
t_stack	*search_node(t_stack *stack, int number);
// void	sort_medium_stack(t_stack **stack_a, t_stack **stack_b);
// void	move_stack(t_stack **a, int largest, int smallest);
// void	sort_large(t_stack **a, t_stack **b);

// stack checkers
int		is_sorted(t_stack *stack);
int		get_smallest(t_stack *stack);
int		get_largest(t_stack *stack);
int		get_second_largest(t_stack *stack, int largest, int smallest);
int		get_larger_value(t_stack *stack, int value);

// median
// int		get_median(int *arr, int n);
// int		mofm(int *arr, int n);
int		*arrayify(t_stack *stack);
int		partition(int *arr, int left, int right);
int		quick_select(int *arr, int left, int right, int k);
int		get_kth_smallest(t_stack *stack, int k);

// sort utils
int		find_smallest_largest(t_stack *stack, int value);

//temp
void	sort_5(t_stack **a, t_stack **b);

#endif
