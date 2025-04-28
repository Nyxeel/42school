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

static size_t ft_wordcount(char const *s, char c)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while(s[i] == c)
		i++;
	while(s[i])
	{
		if(s[i - 1] == c && s[i] != c)
			count++;
		i++;		
	}
	i = 0;
	return (count);	
}

static size_t ft_sepcount(char const *s, char c)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while(s[i])
	{
		if(s[i] == c)
			count++;
		i++;
	}
	return (count);	
}

char **ft_split(char const *s, char c)
{
	size_t wordcount;
	size_t sepcount;
	size_t i;
	size_t j;
	size_t len;
	char **split;

	wordcount = ft_wordcount(s, c);
	sepcount = ft_sepcount(s, c);

	split = (char **)malloc((ft_strlen(s) - sepcount + wordcount) * sizeof(char));
	printf("Wordcount: %zu\n", wordcount);
	printf("Sepcount: %zu\n", sepcount);
	printf("Split Len: %zu\n", ft_strlen(s) - sepcount + wordcount);
	j = 0;
	i = 0;
	len = 0;
	while(s[len] != '\0')
	{
	
		if (s[len] != c)
		{
			*split[j] = s[len];
			j++;
		}
		if (s[len] == c)
		{
			split[i][j] = '\0';
			i++;
			j = 0;
		}		
		len++;
	}
	
	split[i] = NULL;
	return (split);
}

int	main(void)
{
	char str[] = " Hal   jjj   kkk      kk  k k  k   "; // 8 Wörter
	char sep = ' ';


	char **split = ft_split(str, sep);
	int i = 0;
	int j = 0;
	while(split[i])
	{
		printf("Split[%d]: %s\n", i, split[i]);
		i++;
	}
	free(split);
}