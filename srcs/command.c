/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:24:16 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 10:13:25 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	display_cmd(char *cmd)
{
	ft_putstr(cmd);
	ft_putchar('\n');
}

static int	long_commands(int length, int record, char *cmd, t_stacks *stacks)
{
	if (length == 3 && cmd[0] == 'r' && cmd[1] == 'r'
		&& (cmd[2] == 'r' || cmd[2] == 'a'))
		record = reverse_rotate_elements(&stacks->a);
	if (length == 3 && cmd[0] == 'r' && cmd[1] == 'r'
		&& (cmd[2] == 'r' || cmd[2] == 'b'))
		record = reverse_rotate_elements(&stacks->b);
	return (record);
}

static int	defining_commands(char *cmd, t_stacks *stacks)
{
	int	length;
	int	record;

	length = ft_strlen(cmd);
	record = 0;
	if (length == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'a'))
		record = swap_elements(&stacks->a);
	if (length == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'b'))
		record = swap_elements(&stacks->b);
	if (length == 2 && cmd[0] == 'p' && cmd[1] == 'a')
		record = push_element(&stacks->b, &stacks->a);
	if (length == 2 && cmd[0] == 'p' && cmd[1] == 'b')
		record = push_element(&stacks->a, &stacks->b);
	if (length == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'a'))
		record = rotate_elements(&stacks->a);
	if (length == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
		record = rotate_elements(&stacks->b);
	if (length == 3)
		record = long_commands(length, record, cmd, stacks);
	if (record == 0)
		return (0);
	return (1);
}

void	cmd_counter(char *command, int cnt, t_stacks *stacks)
{
	int	i;

	i = ft_abs(cnt);
	while (i)
	{
		if (defining_commands(command, stacks))
		{
			if (stacks->cmd_print == 1)
			{
				display_cmd(command);
			}
			stacks->cmd_cnt++;
		}
		else
			display_error_message(&stacks, 0);
		i--;
	}
}
