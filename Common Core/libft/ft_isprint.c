#include <stdio.h>

int	ft_isprint(int str)
{
	if (str >= 32 && str < 127)
			return (1);
	return	(0); 
}

int	main(void)
{
	int a = 6;
	int b = 'é';

	printf("%d\n", ft_isprint(a));
	printf("%d", ft_isprint(b));
}