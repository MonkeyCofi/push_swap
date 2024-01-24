/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:30:52 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/24 12:15:01 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int))
{
	(void)lst;
	(void)f;
	(void)del;
	return (NULL);
	//t_list	*new_lst;
	//t_list	*ptr;
	//t_list	*temp;

	//ptr = lst;
	//new_lst = NULL;
	//while (ptr)
	//{
	//	temp = ft_lstnew(f(ptr->value));
	//	if (!temp)
	//	{
	//		ft_lstdelone(temp, del);
	//		return (new_lst);
	//	}
	//	ft_lstadd_back(&new_lst, temp);
	//	ptr = ptr->next;
	//}
	//return (new_lst);
}
