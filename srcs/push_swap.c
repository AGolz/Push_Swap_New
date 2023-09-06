/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:47:42 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 06:49:11 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sorting_large_stacks(t_stacks *stacks)
{
	moving_a_to_b(stacks);
	moving_b_to_a(stacks);
	principal_node_min(stacks);
}

static void	sorting_selection(t_stacks *stacks)
{
	if (stacks->length_a == 2)
		sort_too_elements(stacks);
	else if (stacks->length_a == 3)
		sort_three_elements(stacks);
	else if (stacks->length_a == 4)
		sort_four_elements(stacks);
	else if (stacks->length_a == 5)
		sort_five_elements(stacks);
	else
		sorting_large_stacks(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = create_stacks(argc, argv);
	if (stacks->a == NULL)
		exit(free_stacks(&stacks, 0));
	if (stack_is_sorted(stacks) == 1)
		exit(free_stacks(&stacks, 0));
	stacks->cmd_print = 1;
	stacks->length_a = counter_node(stacks->a);
	stack_normalization(stacks);
	sorting_selection(stacks);
	if (argc > 1)
	{
		system("leaks push_swap && ./push_swap");
		printf("Finished checking leaks Mandatory Part on %s!\n", argv[0]);
	}
	return (free_stacks(&stacks, 0));
}
