#include <stdio.h>
#include <stdlib.h>

static int ft_countdigit(int n)
{
	int digits;
	long int num;

	num = n;

	digits = 0;
	if (num == 0)
		digits = 1;

	if (num < 0)
		num = -num;
	while(num > 0)
	{
		num = num / 10;
		digits++;
	}
	return (digits);
}

static char *ft_intochar(char *arr, long int num, int digits, int minus)
{
	int index;
	
	index = digits + minus - 1;
	arr[digits] = '\0';
	while (index >= 0)
	{
		arr[index] = (num % 10) + '0';
		num = num / 10;
		index--;
	}
	if (minus == 1)
			arr[0] = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	char *intarr;
	int digits;
	int minus;
	long int num;

	num = n;
	minus = 0;
	digits = ft_countdigit(n);
	if (num < 0)
	{
		num *= -1;
		minus = 1;
	}
	intarr = (char *)malloc((digits + minus + 1)* sizeof(char));
	if (!intarr)
		return (NULL);
	intarr = ft_intochar(intarr, num, digits, minus);
	return(intarr);
}

int	main(void)
{
	long int ascii = 2147483647;
	char *converted;
	
	converted = ft_itoa(ascii);
	printf("%s", converted);
	free(converted);
}