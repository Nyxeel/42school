
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
	write(1, &c, 1);
	(*counter)++;
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
void	ft_arg_pointer(void *p, int *count)
{
	size_t	hexanum;

	if (!p)
		return (write(1, "(nil)", 5));
	hexanum = (size_t) p;
	ft_putchar_counter("0x", count);
	ft_putnbr_base(hexanum, 16, count, 'p');
}

int	*ft_arg_string(char	*str, int *count)
{
	if (!str)
		return ((int *)-1);
	return (write(1, str, ft_strlen(str)));
}

int	find_arg(char c, va_list ap, int *count)
{
	if (c == 'c')
		ft_putchar_counter(va_arg(ap, int), count);
	if (c == 's')
		return (ft_arg_string(va_arg(ap, char *), count));
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), 10, count, 'z');
	if (c == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), 10, count, 'z');
	if (c == '%')
		ft_putchar_counter(c, count);

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
		while (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
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

	i = ft_printf("c %s %d %x %u", "string", 452); 			// Hexa Return

	printf("\n\nPrintf Return: %d", i);



/* 	i = ft_printf("Pointer: %p\n", p); 				// Pointer Return
	printf("Pointer Laenge: %d\n\n", i); */
}
