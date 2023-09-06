/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:45:20 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:20:40 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	valid_int(int value_i, char *value_c)
{
	int		res;
	char	*cr_val;

	res = 0;
	cr_val = ft_itoa(value_i);
	if (ft_strcmp(cr_val, value_c) == 0)
		res = 1;
	if (cr_val)
		free (cr_val);
	return (res);
}

int	not_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_is_sorted(t_stacks *stacks)
{
	t_stack	*stk_a;
	int		last_val;

	if (stacks->b != NULL)
		return (0);
	stk_a = stacks->a;
	last_val = stk_a->value;
	while (stk_a)
	{
		if (last_val > stk_a->value)
			return (0);
		last_val = stk_a->value;
		stk_a = stk_a->next;
	}
	return (1);
}

int	sort_stacks_check(t_stacks *stacks)
{
	t_stack	*stk_a;
	int		last_val;

	stk_a = stacks->a;
	last_val = stk_a->value;
	while (stk_a)
	{
		if (last_val > stk_a->value)
			return (0);
		last_val = stk_a->value;
		stk_a = stk_a->next;
	}
	return (1);
}
