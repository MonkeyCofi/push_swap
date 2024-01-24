/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:57:39 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/24 12:14:35 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*curr;
	t_list	*next;

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
