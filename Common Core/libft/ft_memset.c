#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
    size_t i;   
    unsigned char *arr;

	i = 0;
	arr = s;

    while (i < n)
    {
        arr[i] = (unsigned char) c;
        i++;
    }
	return (s);
}

int main(void)
{
    char arr[10];
    
	printf("%s", (char *)ft_memset(&arr, 'A', sizeof(arr)));
}