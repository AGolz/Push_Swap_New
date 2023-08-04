/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:30:19 by emaksimo          #+#    #+#             */
/*   Updated: 2023/08/04 23:30:18 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int isLinkedListSorted(t_list **stack) {
    t_list *temp = *stack;

    while (temp && temp->next) {
        if (temp->value > temp->next->value) {
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}

static int findMaxBits(t_list **stack)
{
    int maxValue = 0;
    for (t_list *node = *stack; node != NULL; node = node->next) {
        maxValue = node->index > maxValue ? node->index : maxValue;
    }

    int maxBitValue = 0;
    while (maxValue > 0)
    {
        maxBitValue++;
        maxValue >>= 1;
    }

    return maxBitValue;
}

int isLinkedListReversedSorted(t_list **stack) {
    t_list *temp = *stack;

    while (temp && temp->next) {
        if (temp->value < temp->next->value) {  
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}

void processHeadA(int condition, t_list **stack_a, t_list **stack_b, int *elements_pushed) {
    if (condition)
        ra(stack_a);
    else {
        pb(stack_a, stack_b);
        (*elements_pushed)++; 
    }
}

static void radixSort(t_list **stack_a, t_list **stack_b)
{
    int maxBitValue = findMaxBits(stack_a);
    int is_sorted = isLinkedListSorted(stack_a);
    int is_reversed_sorted = isLinkedListReversedSorted(stack_a);

    for (int index = 0; index < maxBitValue; index++)
    {
        int stackSize = ft_lstsize(*stack_a);
        int elements_pushed = 0;

        for (int iteration = 0; iteration < stackSize; iteration++)
        {
            if (is_sorted)
                processHeadA((((*stack_a)->index >> index) & 1) == 1, stack_a, stack_b, &elements_pushed);
            else if (is_reversed_sorted)
                processHeadA((((*stack_a)->index >> index) & 1) == 0, stack_a, stack_b, &elements_pushed);
            else
                processHeadA((((*stack_a)->index >> index) & 1) == 1, stack_a, stack_b, &elements_pushed);
        }

        for (int i = 0; i < elements_pushed; i++)
            pa(stack_a, stack_b);
    }
}

static void insertionSort(t_list **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    
    t_list *sorted = NULL;
    t_list *current = *head_ref;

    while (current != NULL)
    {
        t_list *next = current->next;

        if (sorted == NULL || sorted->index >= current->index)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            t_list *curr = sorted;
            while (curr->next != NULL && curr->next->index < current->index)
            {
                curr = curr->next;
            }
            current->next = curr->next;
            curr->next = current;
        }

        current = next;
    }

    *head_ref = sorted;
}

int isNearlySorted(t_list **stack) {
    t_list *temp = *stack;
    int size = ft_lstsize(*stack);
    int sorted_count = 0;
    
    while (temp && temp->next) {
        if (temp->value <= temp->next->value) {  
            sorted_count++;
        }
        temp = temp->next;
    }

    return ((float)sorted_count / size >= NEARLY_SORTED_THRESHOLD);
}

void smartSort(t_list **stack_a, t_list **stack_b)
{
    if (isNearlySorted(stack_a))
    {
        insertionSort(stack_a);
    }
    else
    {
        radixSort(stack_a, stack_b);
    }
}