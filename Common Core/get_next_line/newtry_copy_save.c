#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
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

ssize_t	find_line(const char *str, int c)
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
char	*trim_the_line(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (NULL);
	sub = NULL;
	i = 0;
	str_len = ft_strlen(s);
	if (start >= str_len || len == 0)
		return (NULL);
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
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
	join[i + j] = '\0';
	free((void *)s1);
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
void	save_the_rest(char **brain, size_t len)
{
	char *tmp;
	if(!*brain)
		return ;
	tmp = *brain;
	*brain = trim_the_line(*brain, len, ft_strlen(*brain) - len);
	free(tmp);
}


ssize_t	newline(char **brain, int fd)
{
	char	*buffer;
	size_t	bytes;


	bytes = 0;
	printf("BRAIN:%s\n", *brain);
	if (!(*brain))
		*brain = ft_strdup("");
	while (((find_line(*brain, '\n')) == -1) || (find_line(*brain, '\0')) == -1 )
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (0);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
			return (free(buffer), 0);
		buffer[bytes] = '\0';
		*brain = ft_strjoin(*brain, buffer);
		free(buffer);
	}
	return (1);
}


char	*get_next_line(int fd)
{
	static char	*brain;
	char		*line;
	size_t		line_len;
	if (!newline(&brain, fd) || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_len = find_line(brain, '\n');
	printf("Line_len: %zu\n", line_len);
	if (line_len >= 0)
	{
		line = trim_the_line(brain, 0, line_len);
		save_the_rest(&brain, line_len + 1);
	}
	else
	{
		line = trim_the_line(brain, 0, ft_strlen(brain));
		free(brain);
		brain = NULL;
	}
	if (line_len == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
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
			if (i == 26)
			{
				printf("LINE: %s\n", line);
				printf("OUT: Stringlaenge: %zu", ft_strlen(line));

			}
			free(line);
			i++;
		}
	close(fd);
	return (0);
}
