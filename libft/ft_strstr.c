/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:31 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strB, const char *strA)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (strA[0] == '\0')
		return ((char *)strB);
	while (strB[i])
	{
		while (strB[i] == strA[j] || strA[j] == '\0')
		{
			i++;
			j++;
			if (strA[i] == '\0')
				return ((char *)&strB[i - j]);
		}
		i++;
	}
	return (NULL);
}
