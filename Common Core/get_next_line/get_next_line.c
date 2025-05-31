/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:35 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/31 18:31:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_function(char **p)
{
	if (!*p)
		return ;
	free(*p);
	*p = NULL;
}

static int	save_the_rest(char **brain, size_t len)
{
	char	*tmp;

	if (!*brain)
		return (-1);
	tmp = *brain;
	*brain = trim_the_line(*brain, len, ft_strlen(*brain) - len);
	if (!*brain)
		return (free_function(&tmp), -1);
	free_function(&tmp);
	return (0);
}

static int	newline(char **brain, int fd)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 0;
	if (!(*brain))
		*brain = ft_strdup("");
	if (!(*brain))
		return (0);
	while (((find_line(*brain, '\n')) == -1))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_function(&buffer), 0);
		if (bytes == 0)
			return (free_function(&buffer), 1);
		buffer[bytes] = '\0';
		*brain = ft_strjoin(*brain, buffer);
		if (!*brain)
			return (free_function(&buffer), 0);
		free_function(&buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*brain;
	char		*line;
	ssize_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || newline(&brain, fd) == 0)
		return (free_function(&brain), NULL);
	line_len = find_line(brain, '\n');
	if (line_len >= 0)
	{
		line = trim_the_line(brain, 0, line_len + 1);
		if (!line)
			return (free_function(&brain), NULL);
		if (save_the_rest(&brain, line_len + 1) == -1)
			return (free_function(&line), NULL);
	}
	else if (brain != NULL && *brain)
	{
		line = trim_the_line(brain, 0, ft_strlen(brain));
		if (!line)
			return (free_function(&brain), NULL);
		free_function(&brain);
	}
	else
		return (free_function(&brain), NULL);
	return (line);
}


/* # include <fcntl.h>   // open
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
			if ( i == 4)
				printf("%s", line);
			free(line);
			i++;
		}
	//if(!line)
	close(fd);
	return (0);
} */
