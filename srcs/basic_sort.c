/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:42:09 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 21:19:54 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>


static int findMinimumValue(t_list *stack, int value)
{
    int minValue = INT_MAX;
    while (stack)
    {
        if (stack->index < minValue && stack->index != value)
            minValue = stack->index;
        stack = stack->next;
    }
    return minValue;
}


static void	sortThreeElements(t_list **stack_a)
{
	t_list	*headNode;
	int		minValue;
	int		nextMinValue;

	headNode = *stack_a;
	minValue = findMinimumValue(*stack_a, -1);
	nextMinValue = findMinimumValue(*stack_a, minValue);
	if (isLinkedListSorted(stack_a))
		return ;
	if (headNode->index == minValue && headNode->next->index != nextMinValue)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (headNode->index == nextMinValue)
	{
		if (headNode->next->index == minValue)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (headNode->next->index == minValue)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void	sortFourElements(t_list **stack_a, t_list **stack_b)
{
	int	distanceToMin;

	if (isLinkedListSorted(stack_a))
		return ;
	distanceToMin = getNodeDistance(stack_a, findMinimumValue(*stack_a, -1));
	if (distanceToMin == 1)
		ra(stack_a);
	else if (distanceToMin == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distanceToMin == 3)
		rra(stack_a);
	if (isLinkedListSorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sortThreeElements(stack_a);
	pa(stack_a, stack_b);
}

void	sortFiveElements(t_list **stack_a, t_list **stack_b)
{
	int	distanceToMin;

	distanceToMin = getNodeDistance(stack_a, findMinimumValue(*stack_a, -1));
	if (distanceToMin == 1)
		ra(stack_a);
	else if (distanceToMin == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distanceToMin == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distanceToMin == 4)
		rra(stack_a);
	if (isLinkedListSorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sortFourElements(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	basicSort(t_list **stack_a, t_list **stack_b)
{
	int	stackSize;

	if (isLinkedListSorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	stackSize = ft_lstsize(*stack_a);
	if (stackSize == 2)
		sa(stack_a);
	else if (stackSize == 3)
		sortThreeElements(stack_a);
	else if (stackSize == 4)
		sortFourElements(stack_a, stack_b);
	else if (stackSize == 5)
		sortFiveElements(stack_a, stack_b);
}
