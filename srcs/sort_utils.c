/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:30:19 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:26:26 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	counter_optimum_b(int optimum_b, int tmp_b, t_stacks *stacks)
{
	if (optimum_b > 0)
		cmd_counter("rb", tmp_b, stacks);
	else
		cmd_counter("rrb", tmp_b, stacks);
}

void	stack_normalization(t_stacks *stacks)
{
	int	cmd;

	set_index(stacks->a);
	stacks->max_sort = get_maximum_nodes(stacks->a);
	stacks->length_a = counter_node(stacks->a);
	if (stacks->length_a - stacks->max_sort->index - stacks->max_sort->sort > 0)
		cmd = stacks->length_a - (stacks->length_a
				- stacks->max_sort->index - stacks->max_sort->sort);
	else
		cmd = ft_abs(stacks->length_a - stacks->max_sort->index \
						- stacks->max_sort->sort);
	cmd = distance_node_from_apex(stacks->length_a, cmd);
	if (stacks->length_a <= 5)
		return ;
	if (cmd > 0)
		cmd_counter("ra", cmd, stacks);
	else
		cmd_counter("rra", cmd, stacks);
}

void	moving_node_b_to_a(t_stacks	*stks)
{
	stks->tmp_b = ft_abs(stks->optimum_b);
	stks->tmp_a = ft_abs(stks->optimum_a);
	while (((stks->optimum_b > 0 && stks->optimum_a > 0) || (stks->optimum_b < 0
				&& stks->optimum_a < 0)) && stks->tmp_b && stks->tmp_a
		&& stks->optimum_pl != -1)
	{
		if (stks->optimum_b > 0)
			cmd_counter("rr", 1, stks);
		else
			cmd_counter("rrr", 1, stks);
		stks->tmp_b--;
		stks->tmp_a--;
	}
	counter_optimum_b(stks->optimum_b, stks->tmp_b, stks);
	if (stks->optimum_pl != -1)
	{
		if (stks->optimum_a > 0)
			cmd_counter("ra", stks->tmp_a, stks);
		else
			cmd_counter("rra", stks->tmp_a, stks);
	}
	cmd_counter("pa", 1, stks);
	if (stks->optimum_pl == -1)
		cmd_counter("ra", 1, stks);
}

void	moving_a_to_b(t_stacks	*stks)
{
	t_stack	*stk_a;

	stk_a = stks->a;
	while (stk_a && stk_a->index != stks->max_sort->index)
	{
		stk_a = stk_a->next;
		cmd_counter("pb", 1, stks);
	}
}

void	moving_b_to_a(t_stacks	*stks)
{
	int		min_cmd;
	int		cmd;
	t_stack	*tmp_b;

	while (stks->b)
	{
		tmp_b = stks->b;
		set_index(stks->a);
		set_index(stks->b);
		stks->length_a = counter_node(stks->a);
		stks->length_b = counter_node(stks->b);
		min_cmd = stack_set_commandd(stks, tmp_b);
		copy_optimum_place(stks);
		while (tmp_b)
		{
			cmd = stack_set_commandd(stks, tmp_b);
			if (min_cmd > cmd)
			{
				min_cmd = cmd;
				copy_optimum_place(stks);
			}
			tmp_b = tmp_b->next;
		}
		moving_node_b_to_a(stks);
	}
}
