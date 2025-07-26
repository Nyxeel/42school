/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.10_power2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 11:17:29 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (i <= n)
	{
		if (i == n)
			return (1);
		i *= 2;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%i", is_power_of_2(atoi(av[1])));
}
