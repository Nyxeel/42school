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

void	*ft_bzero(void *s, size_t n)
{
    size_t i;   
  	i = 0;
    unsigned char *arr = (unsigned char*) s;

	if(n == 0)
		return NULL;
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
	size_t total;

	total = nmemb * size;
	if (size != 0 && !(total / nmemb == size))
		return(malloc(1));
	p = malloc(total);
	if	(p == NULL)
		return(NULL);
	return (ft_bzero(p, total));
}
//malloc(len+1) is nicht die echte string länge wenn zb. start ziemlich am ende von s liegt und dadurch die stringlänge unter len liegen würde!

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub = NULL;
	size_t i;
	size_t str_len;
	
	str_len = ft_strlen(s);
	i = 0;
	if (!s)
        return (NULL);
    if (start >= str_len || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
    while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int main(void)
{
	const char str[] = "Hallo, ich entnehme einen Substring!";
	char *p = ft_substr(str, 30, 20);
	printf("%s", p);
	free(p);
}