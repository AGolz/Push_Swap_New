/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:30 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	if (n == 0)
		return (0);
	ptr_1 = (unsigned char *)arr1;
	ptr_2 = (unsigned char *)arr2;
	i = 0;
	while (*ptr_1 == *ptr_2 && ++i < n)
	{
		ptr_1++;
		ptr_2++;
	}
	return ((int)(*ptr_1 - *ptr_2));
}
