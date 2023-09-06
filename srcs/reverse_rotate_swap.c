/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:51:54 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 01:21:19 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reverse_rotate_elements(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		push_front(stack, principal_nodes_back(stack));
		return (1);
	}
	return (-1);
}

int	rotate_elements(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		push_back(stack, principal_nodes_front(stack));
		return (1);
	}
	return (-1);
}

int	swap_elements(t_stack **stack)
{
	int	temporary_buff;

	if (*stack && (*stack)->next)
	{
		temporary_buff = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temporary_buff;
		return (1);
	}
	return (-1);
}
