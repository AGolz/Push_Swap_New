/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:49:37 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/06 00:42:54 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_ps.h"

char	*ft_gnl_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i++;
	}	
	return (NULL);
}

char	*ft_gnl_strjoin(char *str_1, char *str_2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!str_1)
	{
		str_1 = (char *)malloc(1 * sizeof(char));
		str_1[0] = '\0';
	}
	if (!str_1 || !str_2)
		return (NULL);
	str = malloc((ft_strlen(str_1) + ft_strlen(str_2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (str_1)
		while (str_1[++i] != '\0')
			str[i] = str_1[i];
	while (str_2[c] != '\0')
		str[i++] = str_2[c++];
	str[ft_strlen(str_1) + (ft_strlen(str_2) - 1)] = '\0';
	free(str_1);
	return (str);
}
