#include <stdio.h>

int	ft_isalpha(int str)
{
	if ((str >= 97 && str <= 122 || str >= 65 && str <= 90))
		return (1);
	return	(0); 
}

int	main(void)
{
	int a = 65;
	int b = 'b';
	int c = b;

	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha(b));
	printf("%d", ft_isalpha(c));
}