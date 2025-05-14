/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:38:47 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/14 19:34:38 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



int	ft_newline(char const *brain, char const newline)
{
	int	i;

	i = 0;
	while (brain[i] != '\0')
	{
		if (brain[i] == newline)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_free(char const *buffer, char const *brain)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	if (!buffer || !brain)
		return (NULL);
	join = (char *)ft_calloc(ft_strlen(buffer) + ft_strlen(brain) + 1);
	if (!join)
		return (NULL);
	while (buffer[i])
	{
		join[i] = buffer[i];
		i++;
	}
	j = 0;
	while (brain[j])
	{
		join[i + j] = brain[j];
		j++;
	}
	join[i + j] = '\0';
	free(buffer);
	return (join);
}

char	*ft_strdup_free(const char *buffer)
{
	int		i;
	char	*brain;

	if (src == NULL)
		return (NULL);
	brain = (char *)ft_calloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (brain == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		brain[i] = src[i];
		i++;
	}
	brain[i] = '\0';
	free(buffer);
	return (brain);
}
