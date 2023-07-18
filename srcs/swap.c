/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:47:46 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 16:20:06 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swapElements(t_list **stack)
{
	t_list	*headNode;
	t_list	*nextNode;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	headNode = *stack;
	nextNode = headNode->next;
	if (!headNode && !nextNode)
		displayErrorMessage("Error occured while swapping!");
	tmp_val = headNode->value;
	tmp_index = headNode->index;
	headNode->value = nextNode->value;
	headNode->index = nextNode->index;
	nextNode->value = tmp_val;
	nextNode->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swapElements(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swapElements(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{	
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swapElements(stack_a);
	swapElements(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
