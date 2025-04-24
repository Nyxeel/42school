#include <stdio.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    size_t i;   
  	i = 0;
    unsigned char *ziel = (unsigned char*) dest;
    const unsigned char *quelle = (const unsigned char *) src;

    while (i < n)
    {
        ziel[i] = quelle[i];
        i++;
    }
    return (dest);
}

int main(void)
{
  
}