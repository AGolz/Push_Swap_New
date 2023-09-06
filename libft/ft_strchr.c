/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:31 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	if (str[i] == ch)
		return ((char *)&str[i]);
	while (str[i] != 0)
	{
		if (str[i + 1] == ch)
			return ((char *)&str[i + 1]);
		i++;
	}
	return (NULL);
}
