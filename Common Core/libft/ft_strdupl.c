#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ziel;

	if (src == NULL)
		return (NULL);
	ziel = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ziel == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		ziel[i] = src[i];
		i++;
	}
	ziel[i] = '\0';
	return (ziel);
}

int	main(void)
{
	char	*src;
	char	*ziel;

	src = "That string to be copied";
	ziel = ft_strdup(src);
	printf("%s", ziel);
	free(ziel);
}