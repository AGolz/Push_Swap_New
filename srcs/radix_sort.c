/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:30:19 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 20:47:53 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	findMaxBits(t_list **stack)
{
	t_list	*head;
	int		maxValue;
	int		maxBitValue;

	head = *stack;
	maxValue = head->index;
	maxBitValue = 0;
	while (head)
	{
		if (head->index > maxValue)
			maxValue = head->index;
		head = head->next;
	}
	while ((maxValue >> maxBitValue) != 0)
		maxBitValue++;
	return (maxBitValue);
}

void	radixSort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		index;
	int		iteration;
	int		stackSize;
	int		maxBitValue;

	index = 0;
	head_a = *stack_a;
	stackSize = ft_lstsize(head_a);
	maxBitValue = findMaxBits(stack_a);
	while (index < maxBitValue)
	{
		iteration = 0;
		while (iteration++ < stackSize)
		{
			head_a = *stack_a;
			if (((head_a->index >> index) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		index++;
	}
}
