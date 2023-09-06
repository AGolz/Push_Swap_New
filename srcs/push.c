/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:49:20 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:31:23 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_element(t_stack **stk_destination, t_stack **stk_source)
{
	if (*stk_destination)
	{
		push_front(stk_source, principal_nodes_front(stk_destination));
		return (1);
	}
	return (-1);
}

void	push_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new;
}

void	push_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack	*push_back_int(t_stack **stack, int value)
{
	t_stack	*new;

	new = create_new_node(value);
	if (new == NULL)
		return (NULL);
	push_back(stack, new);
	return (*stack);
}
