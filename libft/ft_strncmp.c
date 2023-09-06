/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:31 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *str_1 == *str_2 && *str_1 != '\0' && *str_2 != '\0')
	{
		str_1++;
		str_2++;
	}
	return ((unsigned char)*str_1 - (unsigned char)*str_2);
}
