#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

char **ft_split(char const *s, char c)
{
	size_t strlen;
	strlen = ft_strlen(s);
}

int	main(void)
{
	char str[] = " Hallo, das ist ein Text zum Splitten, tschau!!!";
	char sep = ' ';

	char **split = ft_split(str, sep);

}