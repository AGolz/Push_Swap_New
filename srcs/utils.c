/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:53:52 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 06:23:24 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

int	free_stacks(t_stacks **stacks, int ret_num)
{
	if (*stacks && (*stacks)->a)
		free_stack(&(*stacks)->a);
	if (*stacks && (*stacks)->b)
		free_stack(&(*stacks)->b);
	if (*stacks)
		free(*stacks);
	return (ret_num);
}

int	stack_set_commandd(t_stacks *stacks, t_stack *tmp_b)
{
	stacks->tmp_pl = get_node_location_index(stacks->a, tmp_b->value);
	stacks->tmp_b = distance_node_from_apex(stacks->length_b, tmp_b->index);
	stacks->tmp_a = distance_node_from_apex(stacks->length_a, stacks->tmp_pl);
	return (node_counter_b_to_a(stacks->tmp_a, stacks->tmp_b, stacks->tmp_pl));
}

void	copy_optimum_place(t_stacks *stacks)
{
	stacks->optimum_pl = stacks->tmp_pl;
	stacks->optimum_b = stacks->tmp_b;
	stacks->optimum_a = stacks->tmp_a;
}

void	display_error_message(t_stacks **stack, int ret_num)
{
	ft_putstr("Error\n");
	free_stacks(stack, ret_num);
	exit(ret_num);
}
