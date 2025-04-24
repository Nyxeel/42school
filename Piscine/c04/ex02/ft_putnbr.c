/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:21:37 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/20 12:21:39 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	ziff;

	ziff = nb;
	if (ziff < 0)
	{
		ft_putchar('-');
		ziff *= -1;
	}
	if (ziff >= 0 && ziff <= 9)
		ft_putchar(ziff + '0');
	if (ziff > 9)
	{
		ft_putnbr(ziff / 10);
		ft_putnbr(ziff % 10);
	}
}
/*
int main(void)
{
    ft_putnbr(-2147483648);
}*/
