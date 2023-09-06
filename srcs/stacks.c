/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:26:52 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 06:33:49 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	create_stack_a(int argc, char **argv, t_stacks *stacks)
{
	int	index;
	int	create_val;

	if (argc > 2)
	{
		index = 1;
		while (index < argc)
		{
			create_val = ft_atoi(argv[index]);
			if (valid_int(create_val, argv[index]) == 0
				|| not_duplicates(stacks->a, create_val) == 0)
				display_error_message(&stacks, ft_free_array(NULL, 1));
			if ((push_back_int(&stacks->a, create_val)) == NULL)
				display_error_message(&stacks, ft_free_array(NULL, 1));
			index++;
		}
	}
	return ;
}

t_stack	*create_new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stacks	*create_stacks(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		display_error_message(&stacks, 1);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->cmd_cnt = 0;
	stacks->cmd_print = 0;
	create_stack_a(argc, argv, stacks);
	return (stacks);
}

t_stack	*get_last_node(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	counter_node(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
