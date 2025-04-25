#include <stdio.h>

int	ft_tolower(int c)
{
	unsigned char d;

	d = c;
	if (d >= 'A' && d <= 'Z')
		return (c + 32);
	return (c);
}

int main(void)
{
	char a = 'A';
	int b = -5;

	printf("%c\n", ft_tolower(a)); // a
	printf("%d\n", ft_tolower(b)); // b
}