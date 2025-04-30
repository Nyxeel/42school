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

void *ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *arr = (unsigned char*) s;

	i = 0;
    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
    return (s);
}

void *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *p;

	if (nmemb == 0 || size == 0)
		return(malloc(0));
	p = malloc(nmemb * size);
	if	(p == NULL)
		return(NULL);
	return (ft_bzero(p, nmemb * size));

}

static int ft_check(char const *set, char const c)
{
	int i;
	i = 0;
	while (set[i]!= '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
	int i;
	
	i = 0;
	if (!s)
        return (NULL);
    if (start > ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
    while (s[start + i] != '\0' && i < len - 1)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t end;
	size_t start;
	char *trim;
	size_t len;

	start = 0;

	while(ft_check(set, s1[start]) != 0)
		start++;
	end = ft_strlen(s1);
	while(ft_check(set, s1[end - 1]))
		end--;
	if (start > end)
		return (ft_calloc(1, sizeof(char)));
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}

int	main(void)
{
	char str[] = "xyxyyx--x--xHELLOyxx";
	char set[] = "xy-";
	char *trim;

	printf("%s\n", str);
	printf("Trimm: %s\n", set);

	trim = (char *)ft_strtrim(str, set);
	printf("%s\n", trim);
	free(trim);
}