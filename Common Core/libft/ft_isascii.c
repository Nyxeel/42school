#include <stdio.h>

int	ft_isascii(int str)
{
	if (str >= 0 && str <= 127)
			return (1);
	return	(0); 
}

int	main(void)
{
	int a = 6;
	int b = 'é';

	printf("%d\n", ft_isascii(a));
	printf("%d", ft_isascii(b));
}