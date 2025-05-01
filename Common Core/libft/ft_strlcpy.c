#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i = 0;    
    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    while (src[i] != '\0')
    {
        i++;
    } 
    return (i);
}


int main() {
    char quelle[] = "ab";
    char ziel[6];

    size_t result = ft_strlcpy(ziel, quelle, sizeof(ziel));

    printf("Ziel: %s\n", ziel);
    printf("Länge von Quelle: %zu\n", result);

    return 0;
}


