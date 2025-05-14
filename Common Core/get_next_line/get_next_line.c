/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:43:08 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/14 23:45:19 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

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

void	*ft_bzero(void *s, size_t n)
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
	return ((void *) s);
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
	return (ft_bzero(p, total));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	sub = NULL;
	str_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= str_len || len == 0)
		return (ft_calloc(1, sizeof(char)));
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

/* char	*ft_trim(char *newline)
{


} */

size_t	find_line(char const *brain, char const newline)
{
	size_t	i;

	i = 0;
	while (brain[i] != '\0')
	{
		if (brain[i] == newline)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
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
	return (join);
}

char	*ft_new(int fd)
{
	int			bytes;
	char static	*brain;
	char		*buffer;
	int			index;

	if (!brain)
		brain = ft_calloc(0, 0);
	bytes = 0;
	while (find_line(brain, '\n'))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
			return (free(buffer), ft_substr(brain, 0, index - 1));
		buffer[bytes] = '\0';
		brain = ft_strjoin(brain, buffer);
		free(buffer);
	}
	index = find_line(brain, '\n');
	char *line = ft_substr(brain, 0, index - 1);
	char *rest = ft_substr(brain, index, ft_strlen(brain) - (index - 1));
	free(brain);
	brain = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = ft_new(fd);
	if (!newline)
		return (NULL);
	//ft_trim(newline);
	return (newline);
}

int	main(void)
{
		int fd = open("aot.txt", O_RDONLY);
		if (fd == -1)
			return (0);
		char *line;

		int i = 0;


		while ((i < 2))
		{
			line = get_next_line(fd);
			if (!line)
				return (0);
			printf("%s", line);
			free(line);
			i++;
		}
	close(fd);
	return (0);
}
#endif
