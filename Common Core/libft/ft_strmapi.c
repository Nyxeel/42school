#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

char manipulate(unsigned int index, char c)
{
	if (index % 2 == 0)
		return ('*');
	return (c);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *hidden;
	unsigned int i;

	i = 0;
	hidden = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	
	while(s[i])
	{
		hidden[i] = f(i, s[i]);
		i++;
	}
	return (hidden);
}

int	main(void)
{
	char const s[] = "Der manipulierende Text";
	char *new;

	new = ft_strmapi(s, manipulate);
	printf("%s\n", new);
}