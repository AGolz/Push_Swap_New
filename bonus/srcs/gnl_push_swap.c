/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:06:32 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 04:00:13 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_ps.h"

static char	*ft_reserv(char *reserve)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (reserve[i])
		str[c++] = reserve[i++];
	str[c] = '\0';
	free(reserve);
	return (str);
}

static char	*ft_get_line(char *reserve)
{
	int		i;
	char	*str;

	i = 0;
	if (!reserve[i] && reserve[i] != '\n')
		return (NULL);
	while (reserve[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*release_line(char *reserve)
{
	reserve[0] = '\0';
	return (reserve);
}

static char	*ft_rd_reserv(int fd, char *reserve, t_stacks *stacks)
{
	int		rd;
	char	*buff;

	rd = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_gnl_strchr(reserve, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd <= 0)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		reserve = ft_gnl_strjoin(reserve, buff);
		cmd_counter(reserve, 1, stacks);
		if (reserve != NULL)
		reserve = release_line(reserve);
	}
	free(buff);
	return (reserve);
}

char	*get_next_line_ps(int fd, t_stacks *stacks)
{
	char		*line;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reserve = ft_rd_reserv(fd, reserve, stacks);
	if (!reserve)
		return (NULL);
	line = ft_get_line(reserve);
	reserve = ft_reserv(reserve);
	return (line);
}
