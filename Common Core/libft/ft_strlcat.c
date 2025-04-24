#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	

	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	//printf("1: %zu\n", ft_strlen(dst));
	while (src[j] != '\0' && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	i = 0;
	while (src[j + i] != '\0')
		i++;
	//printf("2: %zu\n", ft_strlen(dst));
	
	return (ft_strlen(dst) + i + 1);

}

int	main(void)
{
	char dst[27] = "Hallo, liebe"; //12 + 1
	char src[] = " Freunde abcdefgh";		// 8 + 1

	size_t result = ft_strlcat(dst, src, sizeof(dst));
	printf("%s:\n", dst);
	printf("Komplette Stringlänge: %zu\n", result);
}