/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:45:21 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/10 12:48:12 by netrunner        ###   ########.fr       */
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

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *) s;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *) s);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			total;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (size_t)SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	return (ft_bzero(p, total));
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static	int	ft_countdigit(int n)
{
	int			digits;
	long int	num;

	num = n;
	digits = 0;
	if (num == 0)
		digits = 1;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num = num / 10;
		digits++;
	}
	return (digits);
}


int	ft_putnbr_countdigits(int n)
{
	long int	zahl;
	int count = 0;

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

static	char	*ft_intochar(char *arr, long int num, int digits, int minus)
{
	int	index;

	index = digits + minus - 1;
	while (index >= minus)
	{
		arr[index] = (num % 10) + '0';
		num = num / 10;
		index--;
	}
	arr[digits + minus] = '\0';
	if (minus == 1)
		arr[0] = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	char		*intarr;
	int			digits;
	int			minus;
	long int	num;

	num = n;
	minus = 0;
	digits = ft_countdigit(n);
	if (num < 0)
	{
		num *= -1;
		minus = 1;
	}
	intarr = (char *)ft_calloc((digits + minus + 1), sizeof(char));
	if (!intarr)
		return (NULL);
	intarr = ft_intochar(intarr, num, digits, minus);
	return (intarr);
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
	size_t	count;
	size_t sonder;

	if (!str)
		return (0);
	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (is_valid(str[i + 1]))
				count = print_arg(str[i + 1], ap);
			else
			{
				write(1, &str[i + 1], 1);
				sonder = count++;
				printf("\nSonder Count: %zu\n", sonder);
			}
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
			count = i++;
	}
	va_end(ap);
	return (count);
}
int	main(void)
{
	char c = 'a';
	char str[] = "String";
	int i = ft_printf("Mein %s %% startet um %d Uhr! %c" , str, 12, c);
	printf("\nString: %d Zeichen\n", i);

	// $Mein String % startet um 12 Uhr! a$   <<-- 34 Zeichen




}
