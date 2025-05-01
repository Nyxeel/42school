#include <stdio.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    size_t	i;
    unsigned char *s1;
    unsigned char *s2;

    s1 = (unsigned char *)ptr1;
    s2 = (unsigned char *)ptr2;
    
    i = 0;
    while (i < num)
	{
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
	return (0);
}

int main(void)
{
    char s1[] = "Hallo";
    char s2[] = "HalLo";

    printf("%d\n", ft_memcmp(s1, s2, 5));
}