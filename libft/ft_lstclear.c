/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:57:39 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/23 11:40:35 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*curr;
	t_stack	*next;

	if (!lst || !del)
		return ;
	curr = (*lst);
	next = NULL;
	while (curr)
	{
		next = curr->next;
		del(curr->value);
		free(curr);
		curr = next;
	}
	(*lst) = NULL;
	lst = NULL;
}
