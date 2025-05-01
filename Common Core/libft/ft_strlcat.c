#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t buffer;
	
	if (ft_strlen(dst) >= size)
		buffer = size + ft_strlen(src);
	else
		buffer = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (buffer);
}

int	main(void)
{
	char dst[27] = "Hallo, liebe"; //12 + 1
	char src[] = " Freunde abcdefgh";		// 8 + 1

	size_t result = ft_strlcat(dst, src, sizeof(dst));
	printf("%s:\n", dst);
	printf("Komplette Stringlänge: %zu\n", result);
}