 #include <stdio.h>
 #include <unistd.h>

int	ft_hexa_convert(size_t hexanum, char Xx)
{
	char	*base;
	int 	count = 0;

	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (hexanum < 16)
		ft_putchar(base[hexanum % 16]);
	if (hexanum >= 16)
		count += ft_hexa_convert((hexanum / 16), Xx);
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
t_putchar(base[hexanum % 16]);
	p = va_arg(ap, void *);
	if (!p)
		return (write(1, "(nil)", 5));
	hexanum = (size_t) p;
	return ((write(1, "0x", 2) + ft_hexa_convert(hexanum, 'p')));
}
int	main(void)
{
	ft_hexa_convert(3735928559, 'x');
}
