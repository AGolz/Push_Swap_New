/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:51:12 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:17:17 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*principal_nodes_front(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*principal_nodes_back(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	last = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (last->next && last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
	}
	return (tmp);
}

void	principal_node_min(t_stacks *stacks)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		itr_up;

	tmp_a = stacks->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->value < min_node->value)
			min_node = tmp_a;
		tmp_a = tmp_a->next;
	}
	stacks->length_a = counter_node(stacks->a);
	set_index(stacks->a);
	itr_up = distance_node_from_apex(stacks->length_a, min_node->index);
	if (itr_up > 0)
		cmd_counter("ra", itr_up, stacks);
	else
		cmd_counter("rra", itr_up, stacks);
}
