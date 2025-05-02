#include <stdio.h>
#include <stdlib.h>

void	*ft_bzero(void *s, size_t n)
{
    size_t i;   
  	i = 0;
    unsigned char *arr = (unsigned char*) s;

	if(n <= 0)
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
	if (!(total / nmemb == size))
		return(malloc(1));
	p = malloc(nmemb * size);
	if	(p == NULL)
		return(NULL);
	return (ft_bzero(p, nmemb * size));
}

int	main(void)
{
	size_t elements;

	elements = 10;

	int *p = ft_calloc(elements, 0);

	size_t i = 0;
	while (i < elements)
	{
		printf("p[%zu]: %d\n", i, p[i]);
		i++;
	}
	free(p);

}