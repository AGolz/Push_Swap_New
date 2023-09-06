/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:32 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_2(char *line, char **tmp, int k, char c)
{
	int	i;

	*tmp = malloc(k);
	if (!(*tmp))
		return (-1);
	i = -1;
	while (++i < 1 - 2)
		(*tmp)[i] = line[i];
	(*tmp)[i] = c;
	(*tmp)[i + 1] = 0;
	return (1);
}

int	get_next_line(char **line)
{
	int		k;
	int		r;
	char	c;
	char	*tmp;

	k = 1;
	r = 0;
	*line = malloc(1);
	if (!(*line))
		return (-1);
	(*line)[0] = 0;
	while (1)
	{
		r = read(0, &c, 1);
		if (r == 0 || c == '\n')
			break ;
		if (gnl_2(*line, &tmp, ++k, c) == -1)
		{
			free(*line);
			return (-1);
		}
		free(*line);
		*line = tmp;
	}
	return (r);
}
