/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:35 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/22 00:10:17 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save_the_rest(char **brain, size_t len)
{
	char	*tmp;

	if (!*brain)
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!*brain)
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

	if (newline(&brain, fd) == 0)
		return (free(brain), NULL);
	line_len = find_line(brain, '\n');
	if (line_len >= 0)
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
	}
	if (line_len < 0)
		return (free(line), NULL);
	return (line);
}

# include <fcntl.h>   // open
# include <stdio.h>   // printf

int	main(void)
{
		int fd = open("file.txt", O_RDONLY);
		if (fd == -1)
			return (0);
		char *line;

		size_t i = 1;
		line = NULL;
		printf("TEST:012345\n");
		//printf("012345"); 
		while ((line = get_next_line(fd)))
		{
			if (i == 2)
			{
				printf("%s\n", line);
			}
			free(line);
			i++;
		}
	if (!line)
		free(line);
	close(fd);
	return (0);
}
