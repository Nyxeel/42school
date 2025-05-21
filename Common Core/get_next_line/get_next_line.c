
#include "get_next_line.h"

static int	save_the_rest(char **brain, size_t len)
{
	char *tmp;
	if(!*brain)
		return (-1);
	tmp = *brain;
	*brain = trim_the_line(*brain, len, ft_strlen(*brain) - len);
	if (!*brain)
		return (free(tmp), -1);
	free(tmp);
	return (0);
}

static int	newline(char **brain, int fd)
{
	char	*buffer;
	size_t	bytes;

	bytes = 0;
	if (!(*brain))
	{
		*brain = ft_strdup("");
		if (!*brain)
			return (0);
	}
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
			return (free(buffer), 0);
		free(buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*brain;
	char		*line;
	ssize_t		line_len;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || newline(&brain, fd) == 0)
		return (free(brain), NULL);
	line_len = find_line(brain, '\n');
	if (line_len > 0)
	{
		line = trim_the_line(brain, 0, line_len);
		if (!line)
			return (free(brain), NULL);
		if (save_the_rest(&brain, line_len + 1) == -1)
			return (free(line), NULL);
	}
	else
	{
		line = trim_the_line(brain, 0, ft_strlen(brain));
		if (!line)
			return (free(brain), NULL);
		free(brain);
		brain = NULL;
	}
	if (line_len < 0)
		return (free(line), NULL);
	return (line);
}

/* 
# include <fcntl.h>   // open
# include <stdio.h>   // printf

int	main(void)
{
		int fd = open("aot.txt", O_RDONLY);
		if (fd == -1)
			return (0);
		char *line;

		size_t i = 1;
		line = NULL;
		while ((line = get_next_line(fd)))
		{
			if (i == 40)
			{
				printf("%s\n", line);
			}
			free(line);
			i++;
		}
	close(fd);
	return (0);
} */