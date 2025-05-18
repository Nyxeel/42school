#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <fcntl.h>   // open
# include <stdlib.h>  // free
# include <stdio.h>   // printf
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>


size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *) s;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			total;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (size_t)SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}

int	find_line(const char *str, int c)
{
	unsigned char	letter;

	letter = (unsigned char) c;
	int i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			return (i);
		i++;
	}
	if (letter == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	free((void *)s1);
	join[i + j] = '\0';
	return (join);
}
char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	if (src == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	newline(char **brain, int fd)
{
	char	*buffer;
	size_t	bytes;
	int i = 0;
	printf("BRAIN:%p\n", brain);
	if (!(*brain))
		*brain = ft_strdup("");
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (0);
	bytes = read(fd, buffer, BUFFER_SIZE);
	printf("WHILE\n");
	while (bytes)
	{
		printf("LOOP:%i\n", i);

		buffer[bytes] = '\0';
		*brain = ft_strjoin(*brain, buffer);
		if (find_line(*brain, '\n') >= 0)
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
		i++;
	}
	free(buffer);
	return (-1);
}


char	*get_next_line(int fd)
{
	static char	*brain;
	printf("IN\n");
	newline(&brain, fd);
	printf("OUT\n");
	return (brain);
}
int	main(void)
{
		int fd = open("aot.txt", O_RDONLY);
		if (fd == -1)
			return (0);
		char *line;

		int i = 1;
		line = NULL;
		while ((line = get_next_line(fd)))
		{
			if (i == 1)
			{
				printf("LINE %s\n", line);
				//printf("Stringlaenge: %zu", ft_strlen(line));
				free(line);
				break;
			}
			free(line);
			i++;
		}
	close(fd);
	return (0);
}

