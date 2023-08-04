/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:43:15 by cfiora            #+#    #+#             */
/*   Updated: 2023/08/04 23:23:40 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

#define NEARLY_SORTED_THRESHOLD 0.9

void	basicSort(t_list **stack_a, t_list **stack_b);

void	smartSort(t_list **stack_a, t_list **stack_b);
int		isNearlySorted(t_list **stack);

int		pushElement(t_list **stack_to, t_list **stack_from);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

int		reverseRotateElements(t_list **stack);
int		rra(t_list **stack_a);
int     rrb(t_list **stack_b);
int     rrr(t_list **stack_a, t_list **stack_b);

int		rotateElements(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);

int		swapElements(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

void	displayErrorMessage(char *msg);
void	freeStringArray(char **str);
void	bringNodeToTop(t_list **stack, int distance);
int		getNodeDistance(t_list **numStack, int index);
void	deleteLinkedList(t_list **stack);
int		isLinkedListSorted(t_list **stack);


void	enumerateStack(t_list **stack);
void	displayLinkedList(t_list *listHead);

void	validateInputArgs(int argc, char **argv);



//void	optimizedPushSwap(t_list **stack_a, t_list **stack_b);

#endif
