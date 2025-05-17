/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:43:08 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/17 21:38:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80000


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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	if (!s || *s == '\0')
		return (NULL);
	sub = NULL;
	i = 0;
	str_len = ft_strlen(s);
	if (start >= str_len || len == 0)
		return (ft_calloc(0,0));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)ft_calloc((len + 1), sizeof(char));
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
size_t	find_line(const char *str, char const c)
{
	unsigned char	letter;

	letter = (unsigned char) c;
	if (str == NULL)
		return (1);
	while (*str)
	{
		if (*str == letter)
			return (0);
		str++;
	}
	if (letter == '\0')
		return (0);
	return (1);
}

/* size_t	find_line(char const *brain, char const newline)
{
	size_t	i;

	i = 0;
	if (newline == '\0')
		return (0);
	while (brain[i] != '\0')
	{
		if (brain[i] == newline)
			return (0);
		i++;
	}

	return (1);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
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

char	*ft_newline(int fd, char *brain)
{
	int			bytes;
	char		*buffer;
	char		*tmp_brain;

	tmp_brain = NULL;
	while ((find_line(tmp_brain, '\n')) || find_line(tmp_brain, '\0') )
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
		{
			free(tmp_brain);
			return (NULL);
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
		{
			free(buffer);
			free(tmp_brain);
			return (NULL);
		}
		//printf("NUMBER: %d\n", bytes);													/////////////
		buffer[bytes] = '\0';
		if (!tmp_brain)
			
		tmp_brain = ft_strjoin(tmp_brain, buffer);
		if (!tmp_brain)
		{
			free(buffer);
			free(tmp_brain);
			return (NULL);
		}
		free(buffer);
	}
	//printf("TEST: %s\n", brain);																	/////////
	return (tmp_brain);
}

size_t	calc_len(char *line)
{
	size_t len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
			return (len);
		len++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	char		*newline;
	static char	*brain;
	char		*line;
	size_t		line_len;
	char		*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = ft_newline(fd, brain);
	if (!newline)
		return (NULL);
	line_len = calc_len(newline);
	//printf("LEN: %zu\n", line_len);																	/////////
	line = ft_substr(newline, 0, line_len);
	if(!line)
	{
		free (newline);
		return(NULL);
	}
	//printf("Trimmed Line Laenge: %zu\n", ft_strlen(line));													//////
	rest = ft_substr(newline, line_len + 1, ft_strlen(newline));
	if(!rest)
	{
		free(newline);
		free(line);
		return (NULL);
	}
	free(newline);
	brain = rest;
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
			if (i == 39)
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

#endif
