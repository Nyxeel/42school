void *memchr(const void *s, int c, size_t n);
{
    const unsigned char *str;
    unsigned char letter;
    size_t i;

    str = s;
    letter = (unsigned char) c;
    i = 0;
    if (str == NULL)
        return (NULL);
    if (letter == 0)
        return ((char *)str);
    while (i < n)
    {
        if (str == letter)
            return ((unsigned char *) str);
        i++;
    }
    return (NULL);
}
