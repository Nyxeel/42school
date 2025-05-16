
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


int	ft_countdigit(size_t n, size_t basedivider)
{
	int			digits;
	long int	num;

	num = n;
	digits = 0;
	if (num == 0)
		digits = 1;
	while (num > 0)
	{
		num = num / basedivider;
		digits++;
	}
	return (digits);
}

int	ft_putnbr_base(size_t hexanum, size_t divider, char Xx)
{
	char	*base;
	int		count;

	count = ft_countdigit(hexanum, divider);


	if (Xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";

	if (hexanum >= divider)
	{
		ft_putnbr_base((hexanum / divider), divider, Xx);
		write(1, &base[hexanum % divider], 1);
	}
	if (hexanum < divider)
		write(1, &base[hexanum % divider], 1);
	return (count);
}

int	ft_int_check(int nb)
{
	if (nb < 0)
		return (write(1, "-", 1) + ft_putnbr_base((unsigned int) -nb, 10, 'n'));
	else
		return (ft_putnbr_base(nb, 10, 'n'));
}

int	ft_arg_pointer(void *p, char c)
{
	size_t	hexanum;

	if (!p)
		return (write(1,"(nil)", 5));
	else
	{
		hexanum = (size_t) p;
		return (write(1, "0x", 2) + ft_putnbr_base(hexanum, 16, c));
	}
	return (0);
}

int	ft_arg_string(char	*str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (write(1, (char[]){va_arg(ap, int)}, 1));
	if (c == 's')
		return (ft_arg_string(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_int_check(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), 10, 'z'));
	if (c == 'p')
		return (ft_arg_pointer(va_arg(ap, void *), c));
	if (c == 'x' || c == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), 16, c));
	if (c == '%')
		return (write(1, &c, 1));
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
			if (ft_strchr("cspdiuxX%", str[i + 1]) && str[i + 1])
				count += find_arg(str[i + 1], ap);
			else
				count += write(1, &str[i + 1], 1);
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
		return (-1);
	va_start(ap, str);
	result = ft_va_start(str, ap);
	va_end(ap);
	return (result);
}


int main(void)
{
	int ret1, ret2;

	printf("\n--- CHAR TEST ---\n");
	ret1 = ft_printf("Char: [%c]\n", 'A');
	ret2 = printf("Char: [%c]\n", 'A');
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- STRING TEST ---\n");
	ret1 = ft_printf("String: [%s]\n", "Hello, World!");
	ret2 = printf("String: [%s]\n", "Hello, World!");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- POINTER TEST ---\n");
	int x = 42;
	ret1 = ft_printf("Pointer: [%p]\n", &x);
	ret2 = printf("Pointer: [%p]\n", &x);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	ret1 = ft_printf("Null pointer: [%p]\n", (void *)0);
	ret2 = printf("Null pointer: [%p]\n", (void *)0);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- DECIMAL & INTEGER TEST ---\n");
	ret1 = ft_printf("INT_MAX: [%d] INT_MIN: [%i]\n", INT_MAX, INT_MIN);
	ret2 = printf("INT_MAX: [%d] INT_MIN: [%i]\n", INT_MAX, INT_MIN);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- UNSIGNED TEST ---\n");
	ret1 = ft_printf("UINT_MAX: [%u] ZERO: [%u]\n", UINT_MAX, 0);
	ret2 = printf("UINT_MAX: [%u] ZERO: [%u]\n", UINT_MAX, 0);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- HEXADECIMAL TEST ---\n");
	ret1 = ft_printf("Hex lower: [%x] upper: [%X]\n", 305441741, 305441741);
	ret2 = printf("Hex lower: [%x] upper: [%X]\n", 305441741, 305441741);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- PERCENT SIGN TEST ---\n");
	ret1 = ft_printf("100%% sure!\n");
	ret2 = printf("100%% sure!\n");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);



	printf("\n--- DOUBLE SPECIFIERS ---\n");
	ret1 = ft_printf("Mix: [%c][%s][%d][%x]\n", 'X', "Test", -42, 48879);
	ret2 = printf("Mix: [%c][%s][%d][%x]\n", 'X', "Test", -42, 48879);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- INVALID SPECIFIER ---\n");
	ret1 = ft_printf("What happens with %%r?\n");
	ret2 = printf("What happens with %%r?\n");
	ft_printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- NO ARGUMENTS ---\n");
	ret1 = ft_printf("char: %c, int: %d, string: %s\n"); // <- No Arguments!
	ft_printf("Return values: ft: %d\n", ret1);

	ft_printf("\n--- TOO MANY ARGUMENTS ---\n");
	ret1 = ft_printf("only one: %%d = %d\n", 42, 1337, "oops", NULL);
	ft_printf("Return values: ft: %d\n", ret1);


/* 	printf("\n--- TYPE WRONG ---\n");
	ret1 = ft_printf("unsigned: %s\n", -1);
	printf("Return values: ft: %d\n", ret1); */

	char *ptr = NULL;
	printf("\n--- NULL POINTER IN STRING ---\n");
	ret1 = ft_printf("null string: %s\n", ptr);
	printf("Return values: ft: %d\n", ret1);


	printf("\n--- NULL CHAR ---\n");
	ret1 = ft_printf("null char: %c$\n", '\0');
	printf("Return values: ft: %d\n", ret1);

	printf("\n--- ONLY %% 4 TIMES ---\n");
	ret1 = ft_printf("%%%%%%%%\n");
	printf("Return values: ft: %d\n", ret1);

	printf("\n--- STRING ENDS WITH %% ---\n");
	ret1 = ft_printf("invalid: %");
	printf("Return values: ft: %d\n", ret1);

	printf("\n---UNKNOWN FORMATSIGN---\n");
	ret1 = ft_printf("unknown: %q\n", 42);
	printf("Return values: ft: %d\n", ret1);


	printf("\n---CHAINED---\n");
	ret1 = ft_printf("int: %d, hex: %x, char: %c, str: %s, percent: %%\n", 42, 255, 'A', "Hallo");
	printf("Return values: ft: %d\n", ret1);

	return (0);
}
