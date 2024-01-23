/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:29:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/23 19:32:54 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->value);
		tmp = tmp->next;
	}
}
