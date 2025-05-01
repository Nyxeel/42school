#include <stdio.h>

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

int main(void)
{
    int arr[5] = {25, 25, 26, 25};
    char ar[10];

    ft_bzero(arr, sizeof(arr));    
	for (unsigned long int i = 0; i < 7; i++)
        printf("arr[%lu] = %d\n", i, arr[i]);
    ft_bzero(ar, sizeof(ar));    
    printf("ar = %s\n", ar);
	printf("ar = %lu\n", sizeof(arr));
}