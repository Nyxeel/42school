/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.5_do_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/09 12:37:09 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void putnbr(int num)
{
	long int nb;
	nb = num;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		nb += '0';
		write(1, &nb, 1);
	}
}

int	ft_do_op(char *nb, char op, char *nb2)
{
	int result;
	int num;
	int num2;
	
	num = atoi(nb);
	num2 = atoi(nb2);
	if (op == '*')
		result = num * num2;
	else if (op == '/')
		result = num / num2;
	else if (op == '%')
		result = num % num2;
	else if (op == '+')
		result = num + num2;
	else if (op == '-')
		result = num - num2;
	return (result);	
}

int	main(int ac, char **av)
{
	if (ac == 4)
		putnbr(ft_do_op(av[1], av[2][0], av[3]));
	write(1, "\n", 1);
	return (0);
}