

#include "get_next_line.h"

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
	if (!(*brain))
		*brain = ft_strdup("");
	while (((find_line(*brain, '\n')) == -1))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (free(buffer), 0);
		buffer[bytes] = '\0';
		*brain = ft_strjoin(*brain, buffer);
		if (!*brain)
			return 0;
		free(buffer);
	}
	return (1);
}


char	*get_next_line(int fd)
{
	static char	*brain;
	char		*line;
	ssize_t		line_len;
	if (!newline(&brain, fd) || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(brain), NULL);
	line_len = find_line(brain, '\n');
	if (line_len > 0)
	{
		line = trim_the_line(brain, 0, line_len);
		save_the_rest(&brain, line_len + 1);
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
		int fd = open("leer.txt", O_RDONLY);
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
