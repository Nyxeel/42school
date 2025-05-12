
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
	printf("\nCount Unsigned Digits: %d\n", digits);
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
	printf("\nCount Digits: %d\n", digits);
	return (digits);
}

void	ft_putnbr(int n)
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
}

void	ft_putnbr_unsigned(unsigned int n)
{
	long unsigned int	zahl;

	zahl = n;
	if (zahl > 0 && zahl <= 9)
		ft_putchar(zahl + '0');
	if (zahl > 9)
	{
		ft_putnbr(zahl / 10);
		ft_putnbr(zahl % 10);
	}
}

int	ft_hexa_base(size_t hexanum, char Xx, int count)
{
	char	*base;

	count++;
	if (Xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (hexanum >= 16)
	{
		ft_hexa_base((hexanum / 16), Xx, count);
		write(1, &base[hexanum % 16], 1);
	}
	//printf("Count: %d\n", count);
	if (hexanum < 16)
		count += (write(1, &base[hexanum % 16], 1));
	return (printf("\n Hexa Funktion count: %d", count), count);
}

int	ft_arg_pointer(void *p)
{
	size_t	hexanum;

	if (!p)
		return (write(1, "(nil)", 5));
	hexanum = (size_t) p;
	return ((write(1, "0x", 2) + ft_hexa_base(hexanum, 'p', 0)));
}

int	ft_arg_string(char	*str)
{
	if (!str)
		return (-1);
	return (write(1, str, ft_strlen(str)));
}
int	ft_arg_int(int i)
{
	return (ft_putnbr(i), ft_countdigit(i));
}

int	ft_arg_unsigned(unsigned int i)
{
	return (ft_putnbr_unsigned(i), ft_countdigit_unsigned(i));
}

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (write(1, (char[]){va_arg(ap, int)}, 1));
	if (c == 's')
		return (ft_arg_string(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_arg_int(va_arg(ap, int)));
	if (c == 'u')
		return (ft_arg_unsigned(va_arg(ap, unsigned int)));
	if (c == '%')
		return (write(1, &c, 1));
	if (c == 'x' || c == 'X')
		return (ft_hexa_base((va_arg(ap, unsigned int)), c, 0));
	if (c == 'p')
		return (ft_arg_pointer(va_arg(ap, void *)));
	else
		return (0);
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
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
				count += find_arg(str[i + 1], ap);
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
	printf("\nWhile Loop Count: %d\n", count);
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
	//printf("ORIGINAL:Mein %c %% startet um %c:%c Uhr! %c\n", 'c', 'f', 'd', 'e');
	//printf("\nInput Strinlaenge: %zu\n", ft_strlen(str));
	//printf("%d Hexa: %p\n", 42, NULL);

	int i;
	//char p[10];


/*
	i = ft_printf("%s\n", "STREAM");	 	// String Return 	WORKING
	printf("String Laenge: %zu\nString Output: %d\n\n", ft_strlen("STREAM\n"), i);

	i = ft_printf("%c\n", 'c'); 				// Char Return  WORKING
	printf("Char Laenge: %zu\nChar Output: %d\n\n", ft_strlen("c\n"), i);


	i = ft_printf("%u", -42);	 		// Unsigned Return			WORKING
	printf("Unsigned Laenge: %zu\nUnsigned Output:%d\n", ft_strlen("4294967254"), i);

	int i = ft_printf("%i\n", -42);	 		// Int Return 	WORKING
	printf("Int Laenge: %zu\nInt Output: %d\n\n", ft_strlen("-42\n"), i); */

	i = ft_printf("%x", 428888); 			// Hexa Return
	printf("\n\nPrintf Return: %d\n\n", i);


/* 	i = ft_printf("Pointer: %p\n", p); 				// Pointer Return
	printf("Pointer Laenge: %d\n\n", i); */
}
