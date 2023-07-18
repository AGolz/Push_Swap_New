/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:55:45 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 18:55:57 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **stack, t_list *new)
{
 t_list *n;

 if (*stack)
 {
  n = ft_lstlast(*stack);
  n->next = new;
  new->next = NULL;
 }
 else
 {
  *stack = new;
  (*stack)->next = NULL;
 }
}