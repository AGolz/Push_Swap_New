/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:42:55 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 16:34:33 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	displayErrorMessage(char *errorMsg)
{
	ft_putendl_fd(errorMsg, 1);
	exit(0);
}

void	freeStringArray(char **stringArray)
{
	int	i;

	i = 0;
	while (stringArray[i])
		i++;
	while (i >= 0)
		free(stringArray[i--]);
}

int	isLinkedListSorted(t_list **numStack)
{
	t_list	*listHead;

	listHead = *numStack;
	while (listHead && listHead->next)
	{
		if (listHead->value > listHead->next->value)
			return (0);
		listHead = listHead->next;
	}
	return (1);
}

int	getNodeDistance(t_list **numStack, int index)
{
	t_list	*listHead;
	int		distToNode;

	distToNode = 0;
	listHead = *numStack;
	while (listHead)
	{
		if (listHead->index == index)
			break ;
		distToNode++;
		listHead = listHead->next;
	}
	return (distToNode);
}

void	bringNodeToTop(t_list **numStack, int distToNode)
{
	t_list	*listHead;
	int		currentNum;

	if (distToNode == 0)
		return ;
	listHead = *numStack;
	currentNum = ft_lstsize(listHead) - distToNode;
	if (distToNode <= (ft_lstsize(listHead) / 2))
	{
		while (distToNode-- > 0)
			ra(numStack);
	}
	else
	{
		while (currentNum-- > 0)
			rra(numStack);
	}
}

void	deleteLinkedList(t_list **numStack)
{
	t_list	*listHead;
	t_list	*currentNum;

	listHead = *numStack;
	while (listHead)
	{
		currentNum = listHead;
		listHead = listHead->next;
		free(currentNum);
	}
	free(numStack);
}