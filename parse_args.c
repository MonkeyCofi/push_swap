/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:40 by pipolint          #+#    #+#             */
/*   Updated: 2024/01/28 14:59:18 by pipolint         ###   ########.fr       */
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
		nums = ft_split(argv[i++], " \"");
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

static int	is_number(char *arg, char **nums, t_stack **stack)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			ft_free_split(nums);
			ft_putendl_fd("Error", 2);
			clear_stack(stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

static void	check_for_duplicate(t_stack **stack, t_stack *node, char **nums)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp && ft_stacksize((*stack)) > 1)
	{
		if (node->value == tmp->value)
		{
			ft_putendl_fd("Error", 2);
			free(node);
			clear_stack(stack);
			ft_free_split(nums);
			exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
}

char	*join_args(char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	i = 1;
	joined = NULL;
	while (argv[i])
	{
		if (i == 1)
			joined = ft_strjoin(argv[i], "");
		else
		{
			joined = ft_strjoin(joined, " ");
			temp = joined;
			joined = ft_strjoin(temp, argv[i]);
			free(temp);
		}
		i++;
	}
	return (joined);
}
//char	*join_args(char **argv)
//{
//	char	*joined;
//	int		i;

//	i = 1;
//	joined = NULL;
//	while (argv[i])
//	{
//		if (i == 1)
//			joined = ft_strjoin(argv[i], "");
//		else
//		{
//			joined = ft_strjoin(joined, " ");
//			free(joined);
//			joined = ft_strjoin(joined, argv[i]);
//		}
//		i++;
//	}
//	return (joined);
//}

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
		nums = ft_split(argv[i++], " ");
		if (!nums)
		{
			clear_stack(stack);
			exit(EXIT_FAILURE);
		}
		while (nums[j])
		{
			is_number(nums[j], nums, stack);
			node = ft_newnode(ft_atoi(nums[j++]));
			check_for_duplicate(stack, node, nums);
			ft_stackadd_back(stack, node);
		}
		ft_free_split(nums);
	}
}

//void	add_to_stack(t_stack **stack, char **argv)
//{
//	t_stack	*node;
//	char	**nums;
//	int		i;
//	char	*str;

//	i = 0;
//	str = join_args(argv);
//	ft_printf("Str: %s\n", str);
//	nums = ft_split(str, " ");
//	while (nums[i])
//	{
//		if (is_number(nums[i], nums, stack))
//		{
//			node = ft_newnode(ft_atoi(nums[i]));
//			check_for_duplicate(stack, node, nums);
//			ft_stackadd_back(stack, node);
//		}
//		i++;
//	}
//	ft_free_split(nums);
//}
