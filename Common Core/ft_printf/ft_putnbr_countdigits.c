/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_countdigits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:24:40 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/10 19:17:22 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr_countdigits(int n)
{
	long int	zahl;
	int count;

	zahl = n;
	if (zahl < 0)
	{
		ft_putchar_fd('-');
		zahl *= -1;
		count = 1;
		printf("\nCount Minus: %d\n", count);

	}
	if (zahl >= 0 && zahl <= 9)
	{
		printf("3 Count: %d\n", count);
		ft_putchar_fd(zahl + '0');
	}
	if (zahl > 9)
	{
		count += 1 + ft_putnbr_countdigits(zahl / 10);
		printf("2 Count: %d\n", count);
		ft_putnbr_countdigits(zahl % 10);
	}
	return (count);
}

int	main(void)
{
	long int zahl = -2147483648;
	int count = ft_putnbr_countdigits(zahl);
	printf("\nCount:%d", count);
}
