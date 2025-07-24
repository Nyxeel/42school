/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.4_lcm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/24 11:08:47 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	if (a > b)
		lcm = a;
	else
		lcm = b;
	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}

int	main(int ac, char** av)
{
	if (ac == 3)
		printf("%i\n",lcm(atoi(av[1]), atoi(av[2])));
	else
		write(1, "\n", 1);
}
