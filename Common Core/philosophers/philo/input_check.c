/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:17:22 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/18 23:06:38 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	number_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (false);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	input_check(char **av)
{
	size_t		i;
	long long	num;

	i = 1;
	while (av[i])
	{
		if (!number_check(av[i]))
			return (printf("NUMBER CHECK FAIL\n"), false);
		num = ft_atoi(av[i]);
		if (i == 1 || i == 5)
		{
			if (num <= 0 || num > INT_MAX)
				return (printf("invalide Zahl an Philos\n"), false);
		}
		else
		{
			if (num < 0 || num > INT_MAX)
				return (printf("invalide Zahl für av[%zu]\n", i), false);
		}
		i++;
	}
	return (true);
}
