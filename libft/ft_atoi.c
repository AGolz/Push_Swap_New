/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:39:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:29 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			negative;
	int			i;

	num = 0;
	i = ft_skipspace(str);
	negative = 1;
	while (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		negative = -1;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		if (num != -2147483648 && num < 0 && negative == -1)
			return (0);
		else if (num != -2147483648 && num < 0)
			return (-1);
		i++;
	}
	return (num * negative);
}
