/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:53:52 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 16:27:17 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	isNumInArgs(int targetNum, char **argv, int index)
{
	index++;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) == targetNum)
			return (1);
		index++;
	}
	return (0);
}

static int	isValidNumber(char *targetNum)
{
	int	index;

	index = 0;
	if (targetNum[0] == '-')
		index++;
	while (targetNum[index])
	{
		if (!ft_isdigit(targetNum[index]))
			return (0);
		index++;
	}
	return (1);
}

void	validateInputArgs(int argc, char **argv)
{
	int		index;
	long	currentNum;
	char	**inputValues;	

	index = 0;
	if (argc == 2)
		inputValues = ft_split(argv[1], ' ');
	else
	{
		index = 1;
		inputValues = argv;
	}
	while (inputValues[index])
	{
		currentNum = ft_atoi(inputValues[index]);
		if (!isValidNumber(inputValues[index]))
			displayErrorMessage("Error");
		if (isNumInArgs(currentNum, inputValues, index))
			displayErrorMessage("Error");
		if (currentNum < -2147483648 || currentNum > 2147483647)
			displayErrorMessage("Error");
		index++;
	}
	if (argc == 2)
		freeStringArray(inputValues);
}