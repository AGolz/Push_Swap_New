/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:02:23 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 06:53:57 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_stacks		*stacks;
	char			*cr_com;

	stacks = create_stacks(argc, argv);
	if (argc == 2)
	{
		if (ft_isdigit(*argv[1]) == 0)
			display_error_message(&stacks, ft_free_array(NULL, 1));
	}
	stacks->cmd_print = 0;
	if (stacks->a == NULL)
		exit(free_stacks(&stacks, 0));
	cr_com = get_next_line_ps(0, stacks);
	while (cr_com != NULL)
	{
		free(cr_com);
		get_next_line_ps(0, stacks);
	}
	free(cr_com);
	if (sort_stacks_check(stacks))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (argc > 1)
	{
		system("leaks checker && ./checker");
		printf("Finished checking leaks Bonus Part on %s!\n", argv[0]);
	}
	return (free_stacks(&stacks, 0));
}
