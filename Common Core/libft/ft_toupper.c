#include <stdio.h>

int	ft_toupper(int c)
{
	unsigned char d;

	d = c;
	if (d >= 'a' && d <= 'z')
		return (c - 32);
	return (c);
}

int main(void)
{
	char a = 'a';
	int b = -5;
	
	printf("%c\n", ft_toupper(a)); // A
	printf("%c\n", ft_toupper(b)); // B
}