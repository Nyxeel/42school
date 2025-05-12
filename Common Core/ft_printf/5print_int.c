/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5print_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/11 23:07:49 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr_countdigits(int n)
{
	long int	zahl;
	int			count;

	count = 0;
	zahl = n;
	if (zahl < 0)
	{
		ft_putchar_fd('-');
		zahl *= -1;
	}
	if (zahl >= 0 && zahl <= 9)
		ft_putchar_fd(zahl + '0');
	if (zahl > 9)
	{
		ft_putnbr_countdigits(zahl / 10);
		ft_putnbr_countdigits(zahl % 10);
	}
	return (count);
}

static	int	ft_countdigit(int n)
{
	int			digits;
	long int	num;

	num = n;
	digits = 0;
	if (num <= 0)
	{
		digits = 1;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		digits++;
	}
	return (digits);
}

int	ft_arg_int(int i, va_list ap)
{
	i = va_arg(ap, int);
	ft_putnbr_countdigits(i)
	return (ft_countdigit(int i));
}
