/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:50 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/13 19:16:34 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_move(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(move, "ra", 2))
		rotate(a, 'a', 0);
	else if (!ft_strncmp(move, "rb", 2))
		rotate(b, 'b', 0);
	else if (!ft_strncmp(move, "rr", 2))
		rr(a, b);
	else if (!ft_strncmp(move, "sa", 2))
		swap(a, 'a', 0);
	else if (!ft_strncmp(move, "sb", 2))
		swap(b, 'b', 0);
	else if (!ft_strncmp(move, "ss", 2))
		ss(a, b);
	else if (!ft_strncmp(move, "rra", 3))
		reverse_rotate(a, 'a', 0);
	else if (!ft_strncmp(move, "rrb", 3))
		reverse_rotate(b, 'b', 0);
	else if (!ft_strncmp(move, "rrr", 3))
		rrr(a, b);
	else if (!ft_strncmp(move, "pa", 2))
		push(a, b, 'a');
	else if (!ft_strncmp(move, "pb", 2))
		push(b, a, 'b');
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*move;

	add_to_stack(&a, argv);
	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		exec_move(move, &a, &b);
		move = get_next_line(STDIN_FILENO);
	}
}