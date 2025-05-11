
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
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

int	ft_putnbr(int n)
{
	long int	zahl;

	zahl = n;
	if (zahl < 0)
	{
		ft_putchar('-');
		zahl *= -1;
	}
	if (zahl >= 0 && zahl <= 9)
		ft_putchar(zahl + '0');
	if (zahl > 9)
	{
		ft_putnbr(zahl / 10);
		ft_putnbr(zahl % 10);
	}
	return (ft_countdigit(zahl));
}

int	ft_hexa_convert(size_t hexanum, char Xx)
{
	char	*base;
	int 	count = 0;
	char c;

	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (hexanum >= 16)
	{
		ft_hexa_convert((hexanum / 16), Xx);
		c = base[hexanum % 16];
		write(1, &c, 1);
	}
	if (hexanum < 16)
	{
		hexanum = base[hexanum % 16];
		write(1, &hexanum, 1);
	}
	return (count);
}

int	ft_arg_hexa(char c, va_list ap)
{
	unsigned int	hexa;

	hexa = va_arg(ap, unsigned int);
	return (ft_hexa_convert(hexa, c));
}

int	ft_arg_pointer(void *p, va_list ap)
{
	size_t	hexanum;

	p = va_arg(ap, void *);
	if (!p)
		return (write(1, "(nil)", 5));
	hexanum = (size_t) p;
	return ((write(1, "0x", 2) + ft_hexa_convert(hexanum, 'p')));
}

int	ft_arg_int(int i, va_list ap)
{
	i = va_arg(ap, int);
	return (ft_putnbr(i));
}


int	ft_arg_char(char c, va_list ap)
{
	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_arg_string(char	*str, va_list ap)
{
	str = va_arg(ap, char *);
	if (!str)
		return (-1);
	return (write(1, str, ft_strlen(str)));
}

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_arg_char(c, ap));
	if (c == 's')
		return (ft_arg_string(NULL, ap));
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_arg_int(0, ap));
	if (c == '%')
		return (write(1, &c, 1));
	if (c == 'x' || c == 'X')
		return (ft_arg_hexa(c, ap));
	if (c == 'p')
		return (ft_arg_pointer(NULL, ap));
	else
		return (0);
}
int is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
int	ft_va_start(const char *str, va_list ap)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (is_valid(str[i + 1]))
				count += find_arg(str[i + 1], ap);
			else
				return (-1);
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
		{
			count += 1,
			i++;
		}
	}
	printf("\nWhile Loop Count: %d  i:%d\n", count, i);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;

	if (!str)
		return (0);
	va_start(ap, str);
	result = ft_va_start(str, ap);
	va_end(ap);
	return (result);
}


int	main(void)
{
	//char c = 'a';
	//char *str2 = "Stream";

	//char *str = "Mein c % startet um f:d Uhr! e";
	//printf("\nInput Strinlaenge: %zu\n", ft_strlen(str));
	char p[10];

	int i = ft_printf("%d Hexa: %p\n", 42, p);
	//printf("ORIGINAL:Mein %c %% startet um %c:%c Uhr! %c\n", 'c', 'f', 'd', 'e');
	printf("\nft_printf Return: %d\n", i);
	printf("%d Hexa: %p\n", 42, NULL);
}
