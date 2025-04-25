#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    //unsigned char *haufen;
    //unsigned char *nadel;
    size_t i;
    size_t j;

    //haufen = (unsigned char) haystack;
    //nadel = needle;

    i = 0;
    j = 0;

    if (needle[0] == NULL)
        return ((char *)haystack);
    while(i < n && haystack[i] != '\0')
    {
        printf("%zu\n", i);
        while (haystack[i + j] == needle[j] && i + j < n)
        {
            printf("%zu\n", j);
            if (needle[j + 1] == '\0')
                return ((char *)haystack + i);
            j++;
        }
        i++;
    }
    return (NULL);
}

int main(void) 
{
    
    const char big[] = "Hi schöne Welt";
    const char little[] = "Welt ";

    printf("%s", ft_strnstr(big, little, 100));
}
