/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1_addprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/23 13:57:28 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	long int n;
	n = nb;


	if (n < 0)
		write(1, "-", 1);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		n += '0';
		write(1, &n, 1);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int minus;
	int num;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	return (num * minus);
}

int	isprime(int nb)
{
	int n = 2;

	while (n < nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	add_prime_sum(int nb)
{
	int	i = 2;
	int 	result;

	result = 0;
	while (i <= nb)
	{
		if (isprime(i))
			result = result + i;
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	int result;

	result = 0;
	if (ac != 2 || ft_atoi(av[1]) < 0)
	{
		write(1, "0\n", 2);
		exit(1);
	}
	result = add_prime_sum(ft_atoi(av[1]));
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
