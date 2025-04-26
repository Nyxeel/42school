#include <stdio.h>
#include <stdlib.h>

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

	p = malloc(nmemb * size);
	if	(p == NULL)
		return(NULL);
	return (ft_bzero(p, nmemb * size));

}

int	main(void)
{
	size_t elements;

	elements = 10;

	int *p = ft_calloc(elements, sizeof(int));

	int i = 0;
	while (i < elements)
	{
		printf("p[%d]: %d\n", i, p[i]);
		i++;
	}

}