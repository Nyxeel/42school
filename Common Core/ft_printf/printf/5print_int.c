/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5print_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/12 17:50:30 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_countdigit_unsigned(unsigned int n)
{
	int					digits;
	long unsigned int	num;

	num = n;
	digits = 0;
	while (num > 0)
	{
		num = num / 10;
		digits++;
	}
	return (digits);
}

int	ft_countdigit(int n)
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

void	ft_putnbr_unsigned(unsigned int n)
{
	long unsigned int	zahl;

	zahl = n;
	if (zahl > 0 && zahl <= 9)
		write(1, &(char){zahl + '0'}, 1);
	if (zahl > 9)
	{
		ft_putnbr_unsigned(zahl / 10);
		ft_putnbr_unsigned(zahl % 10);
	}
}

void	ft_putnbr(int n)
{
	long int	zahl;

	zahl = n;
	if (zahl < 0)
	{
		write(1, "-", 1);
		zahl *= -1;
	}
	if (zahl >= 0 && zahl <= 9)
		write(1, &(char){zahl + '0'}, 1);
	if (zahl > 9)
	{
		ft_putnbr(zahl / 10);
		ft_putnbr(zahl % 10);
	}
}

int	ft_arg_int(int i)
{
	return (ft_putnbr(i), ft_countdigit(i));
}

int	ft_arg_unsigned(unsigned int i)
{
	return (ft_putnbr_unsigned(i), ft_countdigit_unsigned(i));
}
