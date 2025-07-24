/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.7_print_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/24 13:36:58 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	print_hex(int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb > 16)
		print_hex(nb / 16);
	write(1, &base[nb % 16], 1);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (nb * minus);
}

int	main(int ac, char** av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	else
		printf("\n");
}


