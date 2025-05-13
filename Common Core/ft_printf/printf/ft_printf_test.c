
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
void	ft_putchar_counter(char c, int *counter)
{
	if (write(1, &c, 1) == 1)
		counter = (int *)-1;
	else
		(*counter)++;
}
void	ft_putstr_counter(char *s, int *count)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_counter(s[i], count);
		i++;
	}
}
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

void	*ft_arg_string(char	*str, int *count)
{
	if (!str)
		return (NULL);
	ft_putstr_counter(str, count);
	return NULL;
}

void	find_arg(char c, va_list ap, int *count)
{
	if (c == 'c')
		ft_putchar_counter(va_arg(ap, int), count);
	if (c == 's')
		ft_arg_string(va_arg(ap, char *), count);
	if (c == 'd' || c == 'i')
		ft_int_check(va_arg(ap, int), count);
	if (c == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), 10, count, 'z');
	if (c == 'p')
		ft_arg_pointer(va_arg(ap, void *), count, c);
	if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), 16, count, c);
	if (c == '%')
		ft_putchar_counter(c, count);
}
char	*ft_strchr(const char *str, int c)
{
	unsigned char	letter;

	letter = (unsigned char) c;
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == letter)
			return ((char *)str);
		str++;
	}
	if (letter == '\0')
		return ((char *)str);
	return (NULL);
}
int	ft_va_start(const char *str, va_list ap)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]) && str[i + 1])
				find_arg(str[i + 1], ap, &count);
			else
				return (-1);
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
		{
			i++;
			count += 1;
		}
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
	int ret1;

printf("\n---CHAINED---\n");
	ret1 = ft_printf("int: %d, hex: %x, char: %c, str: %s, percent: %%\n", 42, 255, 'A', "Hallo");
	printf("Return values: ft: %d\n", ret1);







}
