#include "push_swap.h"

int     get_smaller_value(t_stack *stack, int value)
{
        int     smallest;

        smallest = get_smallest(stack);
        while (stack)
        {
                if (stack->value > smallest && stack->value < value)
                        smallest = stack->value;
                stack = stack->next;
        }
        return (smallest);
}

t_stack	*get_node(t_stack *node, int value)
{
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

