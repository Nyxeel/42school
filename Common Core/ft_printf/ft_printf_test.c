/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:45:21 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/10 19:57:19 by pjelinek         ###   ########.fr       */
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
	{
		count++;
		ft_putchar_fd(zahl + '0');
	}
	if (zahl > 9)
	{
		count = 1 + ft_putnbr_countdigits(zahl / 10);
		ft_putnbr_countdigits(zahl % 10);
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	print_arg(char c, va_list ap)
{
	char			*str;
	size_t			i;

	str = NULL;
	i = 0;
	if (c == 'c')
	{
		c = va_arg(ap, int);
		return (1 + write(1, &c, 1));
	}
	if (c == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			return (0);
		write(1, str, ft_strlen(str));
		//printf("\nStrlen: %zu\n", ft_strlen(str));
		return (ft_strlen(str));
	}
	if (c == 'p')
	{
		write(1, "xXPointerXx", 11);
		return (11);
	}
	if (c == 'd' || c == 'i' || c == 'u')
	{
		i = va_arg(ap, int);
		return (ft_putnbr_countdigits(i));
	}
	if (c == 'x' || c == 'X')
		write(1, "--HexDez--", 10);
	return (10);
}

int is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	count = 0;

	if (!str)
		return (0);
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (is_valid(str[i + 1]))
				count += print_arg(str[i + 1], ap);
			else
				(write(1, &str[i + 1], 1), count += 1);
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
			(count += 1, i++);
	}
	va_end(ap);
	return (count);
}
int	main(void)
{
	//char c = 'a';
	char *str2 = "String";

	char *str = "Mein String % startet um 12 Uhr! a q";
	printf("Strinlaenge: %zu\n", ft_strlen(str));

	int i = ft_printf("Mein %s %% startet um %d Uhr! %u\n" , str2, 12, -42);

	printf("ft_printf Return: %d Zeichen\n", i);

	//printf("\nTEST Unsigned Int: %u \n", -42);


	// $Mein String % startet um 12 Uhr! a$   <<-- 34 Zeichen



	// Too many arg calls in the formatstring
	//printf("TEST: String %s to be at home at %d o'clock %c", "needs", 4);






}
