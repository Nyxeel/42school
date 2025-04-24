#include <stdio.h>

int	ft_isdigit(int str)
{
	if (str >= 0 && str <= 9)
			return (1);
	return	(0); 
}

int	main(void)
{
	int a = 6;
	int b = 'b';

	printf("%d\n", ft_isdigit(a));
	printf("%d", ft_isdigit(b));
}