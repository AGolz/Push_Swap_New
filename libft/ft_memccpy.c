/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:30 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str_1;
	const unsigned char	*str_2;

	str_1 = (unsigned char *)dst;
	str_2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str_1[i] = str_2[i];
		if (str_1[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		++i;
	}
	return (NULL);
}
