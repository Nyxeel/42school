#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
    unsigned char letter;
    //int i;

    letter = (unsigned char) c;

    if (str == NULL)
        return (NULL);
    if (letter == 0)
        return ((char *)str);
   // i = 0;
    while (*str)
    {
        if (*str == letter)
            return ((char *)str);
        str++;
    }
    return (NULL);
}

int main(void)
{
    char str[] = "ort das ich suche";
    char suche = 'd';

    char *p = ft_strrchr(str, suche);
    if (p != NULL)
    {
        printf("Gefunden: '%c'\n", *p);                // → s
        printf("Ab hier: \"%s\"\n", p);                 // → s wort das ich suche
        printf("Index im String: %ld\n", p - str);      // → 2 (weil p zeigt auf str[2])
    }
    else
        printf("Nicht gefunden.\n");
}
