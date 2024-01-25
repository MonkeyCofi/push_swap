/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:00 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/25 19:45:37 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
	//char	*new;
	//int		i;
	//int		s2_i;

	//new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	//if (!new)
	//	return (NULL);
	//i = 0;
	//s2_i = 0;
	//while (s1[i] != '\0')
	//{
	//	new[i] = s1[i];
	//	i++;
	//}
	//while (s2[s2_i] != '\0')
	//{
	//	new[i] = s2[s2_i];
	//	s2_i++;
	//	i++;
	//}
	//new[i] = '\0';
	//return (new);
}
