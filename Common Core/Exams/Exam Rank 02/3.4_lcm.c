/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.4_lcm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 11:40:14 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);

 */

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
