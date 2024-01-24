/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:40 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/24 12:10:04 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arguments(char **argv)
{
	char	**nums;
	int		i;
	int		j;
	int		res;
	int		arg_count;

	i = 1;
	arg_count = 0;
	while (argv[i])
	{
		j = 0;
		nums = ft_split(argv[i++], ' ');
		if (!nums)
			exit(EXIT_FAILURE);
		while (nums[j])
		{
			res = ft_atoi(nums[j++]);
			(void)res;
			arg_count++;
		}
		ft_free_split(nums);
	}
	return (arg_count);
}

/*
* check if argument is a number
* if it isn't a number, free double array and stack and return
*/
int	is_number(char *arg, char **nums, t_stack **stack)
{
	int	i;

	(void)stack;
	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			ft_free_split(nums);
			ft_putendl_fd("Argument must only consist of numbers", 2);
			clear_stack(stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

/*
* go through the stack
* if there is an error, free stack and exit
*/
int	is_duplicate(t_stack **stack)
{
	(void)stack;
	return (1);
}

/*
* go through each argument
* use split in case the arguments are input as one singular string
* if the current number is not in the stack:
	** check if the stack is empty
		** if it is, set the number as the first node of the stack
	** else if the stack is full
		** exit
	** else
		** add the number as the next number in the stack
* else if the current number already exists, return error
*/
void	add_to_stack(t_stack **stack, char **argv)
{
	t_stack	*node;
	char	**nums;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		nums = ft_split(argv[i++], ' ');
		if (!nums)
			exit(EXIT_FAILURE);
		while (nums[j])
		{
			if (is_number(nums[j], nums, stack))
			{
				node = ft_lstnew(ft_atoi(nums[j++]));
				ft_lstadd_back(stack, node);
			}
			else
				exit(EXIT_FAILURE);
		}
		ft_free_split(nums);
	}
}
