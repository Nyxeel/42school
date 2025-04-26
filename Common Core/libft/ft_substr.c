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

//malloc(len+1) is nicht die echte string länge wenn zb. start ziemlich am ende von s liegt und dadurch die stringlänge unter len liegen würde!

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
	char *p = ft_substr(str, 20, 20);
	printf("%s", p);
	free(p);
}