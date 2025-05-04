
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ziel;
	unsigned char	*quelle;
	size_t i;

	ziel = (unsigned char *) dest;
	quelle = (unsigned char *) src;
	i = 0;
	if (ziel == quelle || n == 0)
		return ((void*)dest);
	if (ziel < quelle)
		while (i < n)
		{
			ziel[i] = quelle[i];
			i++;
		}
	else
		while (n--)
			ziel[n] = quelle[n];
	return ((void *)dest);
}

/* int	main(void)
{
	char array[] = "ABCDEFGHIJKLMNO";
	char arr[] = "ABCDEFGHIJKLMNO";

	char *p = ft_memmove(&arr[8], &arr[3], 7);
	printf("%s\n\n", p);
	char *s = memmove(&array[8], &array[3], 7);
	printf("%s\n\n", s);
} */
