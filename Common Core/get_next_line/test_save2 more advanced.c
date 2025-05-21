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
		return (free((void *)s), NULL);
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
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (free((void *)s1), NULL);
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
	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (free((void *)src), NULL);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int	save_the_rest(char **brain, size_t len)
{
	char *tmp;
	if(!*brain)
		return (-1);
	tmp = *brain;
	*brain = trim_the_line(*brain, len, ft_strlen(*brain) - len);
	if(!*brain)
		return (free(tmp), -1);
	free(tmp);
	return (0);
}


ssize_t	newline(char **brain, int fd)
{
	char	*buffer;
	size_t	bytes;

	bytes = 0;
	if (!(*brain))
		*brain = ft_strdup("");
	while (((find_line(*brain, '\n')) == -1))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (free(buffer), -1);
		buffer[bytes] = '\0';
		*brain = ft_strjoin(*brain, buffer);
		if (!*brain)
			return (free(buffer), -1);
		free(buffer);
	}
	return (1);
}


char	*get_next_line(int fd)
{
	static char	*brain;
	char		*line;
	ssize_t		line_len;
	if (newline(&brain, fd) <= 0|| fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(brain), NULL);
	line_len = find_line(brain, '\n');
	if (line_len > 0)
	{
		line = trim_the_line(brain, 0, line_len);
		if (!line)
			return (NULL);
		if(save_the_rest(&brain, line_len + 1) < 0)
			return (free(line), NULL);
	}
	else
	{
		line = trim_the_line(brain, 0, BUFFER_SIZE);

		free(brain);
		brain = NULL;
	}
	if (line_len <= 0)
		return (free(line), NULL);
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
