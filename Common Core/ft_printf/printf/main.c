
#include "libftprintf.h"

void	ft_putchar_counter(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

int	*ft_putnbr_base(size_t hexanum, size_t basedivider, int *counter, char Xx)
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
	return (counter);
}

int	main(void)
{
	//char c = 'a';
	//char *str2 = "Stream";

	//char *str = "Mein c % startet um f:d Uhr! e";
	//printf("ORIGINAL:Mein %c %% startet um %c:%c Uhr! %c\n", 'c', 'f', 'd', 'e');
	//printf("\nInput Strinlaenge: %zu\n", ft_strlen(str));
	//printf("%d Hexa: %p\n", 42, NULL);

	int i = 0;
	size_t zahl = -42;
	//char p[10];

	ft_putnbr_base(zahl, 16, &i, 'x');
	printf("\n%d", i);
	printf("\n%zx", zahl);



	/* i = ft_printf("%s\n", "STREAM");	 	// String Return 	WORKING
	printf("String Laenge: %zu\nString Output: %d\n\n", ft_strlen("STREAM\n"), i);

	i = ft_printf("%c\n", 'c'); 				// Char Return  WORKING
	printf("Char Laenge: %zu\nChar Output: %d\n\n", ft_strlen("c\n"), i);


	i = ft_printf("%u", -42);	 		// Unsigned Return			WORKING
	printf("Unsigned Laenge: %zu\nUnsigned Output:%d\n", ft_strlen("4294967254"), i);

	i = ft_printf("%i\n", -42);	 		// Int Return 	WORKING
	printf("Int Laenge: %zu\nInt Output: %d\n\n", ft_strlen("-42\n"), i);

	i = ft_printf("%s\n%i\n%d\n%x\n%u\n", "TEST", 125, 765443, 45899, -1); 			// Hexa Return
	printf("\n\nPrintf Return: %d\n\n", i);
	printf("ORIGINAL:%x", -21);


	i = ft_printf("Pointer: %p\n", p); 				// Pointer Return
	printf("Pointer Laenge: %d\n\n", i);*/
}

	/* if (Xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef"; */
