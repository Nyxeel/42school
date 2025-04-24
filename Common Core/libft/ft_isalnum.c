#include <stdio.h>

int	ft_isdigit(int str)
{
	if (str >= 0 && str <= 9)
			return (1);
	return	(0); 
}

int	ft_isalpha(int str)
{
	if ((str >= 97 && str <= 122 || str >= 65 && str <= 90))
		return (1);
	return	(0); 
}


int	ft_isalnum (int str)
{
	if ((ft_isalpha(str) || ft_isdigit(str)))
			return (1);
	return	(0); 
}


int	main(void)
{
	int a = 65;
	int b = 'b';
	int c = f;

	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(b));
	printf("%d", ft_isalnum(c));
}