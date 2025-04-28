#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

size_t ft_split(char const *s, char c)
{
	size_t strlen;
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	// strlen = ft_strlen(s);
	while(s[i] == c)
		i++;
	while(s[i])
	{
		if(s[i - 1] == c && s[i] != c)
			count++;
		//if ((s[i] != c && s[i + 1] == c) || s[i] == c && s[i + 1] == '\0')
		i++;		
	}
	return (count);	
}

int	main(void)
{
	char str[] = " Hal   jjj   kkk      kk  k k  k   "; // 8 Wörter
	char sep = ' ';


	size_t split = ft_split(str, sep);
	printf("Wörter: %zu\n", split);


}