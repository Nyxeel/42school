/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.3_fprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/25 11:04:11 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void fprime(int nb)
{
	int i = 2;
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			printf("%i", i);
			if (nb != i)
				printf("*");
			nb /= i;
		}
		else
			i++;
	}
}

int	main(int ac, char** av)
{
	int i;

	i = 1;
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
}



