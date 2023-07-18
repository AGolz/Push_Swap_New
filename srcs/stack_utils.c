/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:55:20 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 16:38:41 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*findNextMinimum(t_list **stack)
{
	t_list	*listHead;
	t_list	*minNode;
	int		isMinFound;

	minNode = NULL;
	isMinFound = 0;
	listHead = *stack;
	if (listHead)
	{
		while (listHead)
		{
			if ((listHead->index == -1) && (!isMinFound || listHead->value < minNode->value))
			{
				minNode = listHead;
				isMinFound = 1;
			}
			listHead = listHead->next;
		}
	}
	return (minNode);
}

void	enumerateStack(t_list **stack)
{
	t_list	*listHead;
	int		index;

	index = 0;
	listHead = findNextMinimum(stack);
	while (listHead)
	{
		listHead->index = index++;
		listHead = findNextMinimum(stack);
	}
}

void	displayLinkedList(t_list *listHead)
{
	t_list	*currentNum;

	currentNum = listHead;
	while (currentNum != NULL)
	{
		ft_putnbr_fd(currentNum->value, 1);
		ft_putendl_fd("", 1);
		currentNum = currentNum->next;
	}
}