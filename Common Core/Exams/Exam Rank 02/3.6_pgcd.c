/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.6_pgcd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/24 11:52:06 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int    pgcd(unsigned int a, unsigned int b)
{
	unsigned int tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

int	main(int ac, char** av)
{
	if (ac == 3)
		printf("%i\n",pgcd(atoi(av[1]), atoi(av[2])));
	else
		printf("\n");
}