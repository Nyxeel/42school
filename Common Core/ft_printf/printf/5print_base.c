/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5print_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/13 10:20:50 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_putnbr_base(size_t hexanum, size_t basedivider, int *counter, char Xx)
{
	char	*base;

	if (Xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";

	if (hexanum >= basedivider)
	{
		ft_putnbr_base((hexanum / basedivider), basedivider, counter, Xx);
		ft_putchar_counter(base[hexanum % basedivider], counter);
	}
	if (hexanum < basedivider)
		ft_putchar_counter(base[hexanum % basedivider], counter);
}

void	ft_int_check(int nb, int *count)
{
	if (nb < 0)
	{
		ft_putchar_counter('-', count);
		ft_putnbr_base((unsigned int) -nb, 10, count, 'n');
	}
	else
		ft_putnbr_base(nb, 10, count, 'n');
}
void	ft_arg_pointer(void *p, int *count, char c)
{
	size_t	hexanum;

	if (!p)
		ft_putstr_counter("(nil)", count);
	else
	{
		hexanum = (size_t) p;
		ft_putstr_counter("0x", count);
		ft_putnbr_base(hexanum, 16, count, c);
	}
}
