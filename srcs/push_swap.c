/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:47:42 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 21:25:39 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void printStack(t_list **stack)
{
    t_list *temp = *stack;

    while (temp != NULL)
    {
        printf("%d ", temp->index);
        temp = temp->next;
    }

    printf("\n");
}

static void initializeStack(t_list **stack, int argc, char **argv)
{
    t_list  *new;
    char    **args;
    int     index;

    index = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        index = 1;
        args = argv;
    }
    while (args[index])
    {
        new = ft_lstnew(ft_atoi(args[index]));
        ft_lstadd_back(stack, new);
        index++;
    }
    enumerateStack(stack);
    if (argc == 2)
        freeStringArray(args);
}

static void	sortStack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		basicSort(stack_a, stack_b);
	else
		radixSort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	validateInputArgs(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initializeStack(stack_a, argc, argv);
	if (isLinkedListSorted(stack_a))
	{
		deleteLinkedList(stack_a);
		deleteLinkedList(stack_b);
		return (0);
	}
	printf("before\n");
    printf("stack A :\n");
    printStack(stack_a);
    printf("stack B :\n");
    printStack(stack_b);
	sortStack(stack_a, stack_b);
	printf("after \n");
	printf("stack A :\n");
	printStack(stack_a);
	printf("stack B :\n");
	printStack(stack_b);
	deleteLinkedList(stack_a);
	deleteLinkedList(stack_b);
	return (0);
}
