/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:33:57 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/25 19:41:23 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

void	print_array(int a[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (i == arrSize - 1)
			printf("%d\n", a[i]);
		else
			printf("%d ", a[i]);
	}
}

/*
** take the array as a paramter
** split the array into subarrays
	** get the middle point of the array
	** then split 
*/
void	merge_sort(int a[])
{
	return ;
}

int main(void)
{
	char *str = NULL;
	char *str2 = "there";
	char *new = ft_strjoin(str, str2);
	ft_printf("%s\n", new);
	//int a[] = {90, 25, 65, 12, 2};
	//int size = sizeof(a) / sizeof(int);
	//print_array(a, size);
}