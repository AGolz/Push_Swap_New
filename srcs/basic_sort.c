/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:42:09 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:20:40 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_too_elements(t_stacks *stks)
{
	if (stks->a->value > stks->a->next->value)
		cmd_counter("sa", 1, stks);
}

void	sort_three_elements(t_stacks *stks)
{
	while (!sort_stacks_check(stks))
	{
		if ((stks->a->value < stks->a->next->value && stks->a->value
				> stks->a->next->next->value) && (stks->a->next->value
				> stks->a->value && stks->a->next->value
				> stks->a->next->next->value))
			cmd_counter("rra", 1, stks);
		else if ((stks->a->value > stks->a->next->value && stks->a->value
				> stks->a->next->next->value) && (stks->a->next->value
				< stks->a->value && stks->a->next->value
				< stks->a->next->next->value))
			cmd_counter("ra", 1, stks);
		else
			cmd_counter("sa", 1, stks);
	}
}

void	sort_four_elements(t_stacks *stks)
{
	int	minimum_value;

	minimum_value = findminimum_value(stks);
	if (minimum_value == 1)
		cmd_counter("ra", 1, stks);
	else if (minimum_value == 2)
		cmd_counter("ra", 2, stks);
	else if (minimum_value == 3)
		cmd_counter("rra", 1, stks);
	if (sort_stacks_check(stks))
		return ;
	cmd_counter("pb", 1, stks);
	sort_three_elements(stks);
	cmd_counter("pa", 1, stks);
}

void	sort_five_elements(t_stacks *stks)
{
	int	minimum_value;

	minimum_value = findminimum_value(stks);
	if (minimum_value == 1)
		cmd_counter("ra", 1, stks);
	else if (minimum_value == 2)
		cmd_counter("ra", 2, stks);
	else if (minimum_value == 3)
		cmd_counter("rra", 2, stks);
	else if (minimum_value == 4)
		cmd_counter("rra", 1, stks);
	if (sort_stacks_check(stks))
		return ;
	cmd_counter("pb", 1, stks);
	sort_four_elements(stks);
	cmd_counter("pa", 1, stks);
}
