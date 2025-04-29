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
		if(s[i - 1] == c && s[i] != c || ( s[i + 1] == '\0'))
			count++;
		i++;		
	}
	i = 0;
	return (count);	
}

static char *ft_cpy(char const *str, char c)
{
	size_t count;
	size_t i;
	char *p;

	i = 0;
	count = 0;
	while(str[count] != c && str[count] != '\0' )
		count++;
	printf("Len:%zu\n", count);
	p = (char *)malloc((count + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while(i < count && str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
void *ft_freeall()
{
	size_t i;

	i = 0;
	while (i--)
		free(split[i]);
	free(split;)
}*/


char **ft_split(char const *s, char c)
{
	size_t wordcount;
	size_t sepcount;
	size_t i;
	size_t j;
	size_t len;
	char **split;

	wordcount = ft_wordcount(s, c);

	split = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	printf("Wordcount: %zu\n", wordcount);
	j = 0;
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] != c)
		{
			split[j] = ft_cpy(&s[i], c);
			printf("split[%zu]:%s\n", j, split[j]);
			if (j < wordcount)
				j++;
			
			while(s[i] != c && s[i] != '\0')
				i++;
			//if (!split[j])
			//ft_free(split, j);
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

int	main(void)
{
	char str[] = "Wir haben viel Spaß hier zusammen yaaaa juhu!"; // 8 Wörter
	char sep = ' ';


	char **split = (char **)ft_split(str, sep);
	int i = 0;
	int j = 0;
	
	while(split[i])
	{
		printf("**split[%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}