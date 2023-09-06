/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:42:55 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:08:53 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	findminimum_value(t_stacks *stks)
{
	int		min_value;
	int		min_value_index;
	t_stack	*stk_a;

	min_value = stks->a->value;
	min_value_index = 0;
	stk_a = stks->a;
	while (stk_a && stk_a->next)
	{
		if (min_value > stk_a->next->value)
			min_value = stk_a->next->value;
		stk_a = stk_a->next;
	}
	stk_a = stks->a;
	while (stk_a->next && stk_a->value != min_value)
	{
		min_value_index++;
		stk_a = stk_a->next;
	}
	return (min_value_index);
}

void	set_index(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

int	node_counter_b_to_a(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0 && place_b != -1)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	else
		return (ft_abs(a) + ft_abs(b));
}
