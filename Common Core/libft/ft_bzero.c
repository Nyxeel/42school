#include <stdio.h>

void *ft_bzero(void *s, size_t n)
{
    size_t i;   
  	i = 0;
    unsigned char *arr = (unsigned char*) s;

    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
    return (s);
}

int main(void)
{
    int arr[10];
    char ar[10];

    ft_bzero(arr, sizeof(arr));    
	for (int i = 0; i < 10; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    ft_bzero(ar, sizeof(ar));    
    printf("ar = %s\n", ar);
}