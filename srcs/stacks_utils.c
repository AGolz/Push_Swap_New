/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:55:20 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:29:10 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	get_smaller_node(t_stack *stack, t_stack *tmp, t_stack *first)
{
	if (tmp->next == NULL)
	{
		if (first->value < tmp->value)
			return ;
	}
	else
		if (tmp->next->value < tmp->value)
			return ;
	stack->sort++;
	if (tmp->next == NULL)
		tmp = first;
	else
		tmp = tmp->next;
	return ;
}

t_stack	*get_maximum_nodes(t_stack *stack)
{
	int		nodes;
	int		index;
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*max;

	first = stack;
	max = stack;
	nodes = counter_node(stack);
	while (stack)
	{
		tmp = stack;
		index = 0;
		while (index < nodes)
		{
			get_smaller_node(stack, tmp, first);
			index++;
		}
		if (stack->sort >= max->sort)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int	distance_node_from_apex(int stack_len, int node_index)
{
	if (stack_len / 2 >= node_index)
	{
		return (node_index);
	}
	else
	{	
		return ((stack_len - node_index) * -1);
	}
}

int	get_node_location_index(t_stack *stack, int node_value)
{
	t_stack	*optimum;
	int		last_min;

	optimum = NULL;
	last_min = 0;
	while (stack)
	{
		if ((last_min == 0) || (last_min < 0 && stack->value - node_value < 0
				&& stack->value - node_value > last_min) || (last_min > 0
				&& stack->value - node_value < last_min))
		{
			last_min = stack->value - node_value;
			optimum = stack;
		}
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	if (optimum == stack && last_min < 0)
		return (-1);
	if (last_min < 0)
		return (optimum->index + 1);
	else
		return (optimum->index);
}
