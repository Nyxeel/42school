
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
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
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
	ft_putnbr_countdigits(i);
	return (ft_countdigit(i));
}


int	ft_arg_char(char c, va_list ap)
{
	c = va_arg(ap, int);
	return (1 + write(1, &c, 1));
}

int	ft_arg_string(char	*str, va_list ap)
{
	str = va_arg(ap, char *);
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_arg_char(c, ap));
	if (c == 's')
		return (ft_arg_string(NULL, ap));
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_arg_int(0, ap));
	/* if (c == 'x' || c == 'X')
		return (ft_arg_hexa(c));
	if (c == 'p')
		return (ft_arg_pointer((char *) c));*/
	else
		return (0);
}
int is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
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
				(write(1, &str[i + 1], 1), count += 1);
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
			(count += 1, i++);
	}
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
	char c = 'a';
	char *str2 = "String";

	char *str = "Mein String % startet um 12 Uhr! a";
	printf("Strinlaenge: %zu\n", ft_strlen(str));

	int i = ft_printf("Mein %s %% startet um %d Uhr! %c" , str2, 12, c);
	printf("ft_printf Return: %d\n", i);
}
