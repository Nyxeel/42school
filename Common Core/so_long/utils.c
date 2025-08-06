/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/06 15:40:07 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
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
	return (join);
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



int	ft_strcheck(const char *str, int c)
{
	unsigned char	letter;
	int i;

	i = 0;
	letter = (unsigned char) c;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			i++;
		else
			return (0);
	}
	return (1);
}



/////////////////////////////////		ft_split

int	ft_isspace(char c)
{
	if (c == ' ' || c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	ft_wordcount(char const *str , char c)
{
	int i;
	int words;
	bool in_word;

	in_word = false;
	words = 0;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			in_word = false;
		else if (!in_word)
		{
			in_word = true;
			words++;
		}
		i++;
	}
	return (words);
}

static char	*ft_cpy(char const *str, char c)
{
	size_t	count;
	size_t	i;
	char	*p;

	i = 0;
	count = 0;
	while (str[count] != c && str[count] != '\0')
		count++;
	p = (char *)ft_calloc((count + 1), sizeof(char));
	if (!p)
		return (NULL);
	while (i < count && str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_freeall(char **freearr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(freearr[i]);
		i++;
	}
	free(freearr);
}

static char	**ft_split_loop(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			split[j] = ft_cpy(&s[i], c);
			if (!split[j])
				return (ft_freeall(split, j), NULL);
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (split);
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_split_loop(split, s, c));
}





//////////////////////////////////////////////////////////////////////


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

int	find_doubles(char *str, int c)
{
	unsigned char	letter;
	unsigned int	count;
	size_t			i;

	letter = (unsigned char) c;
	count = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			count++;
		i++;
	}
	return (count);
}

int	find_char(char *str, int c)
{
	unsigned char	letter;
	size_t			i;

	letter = (unsigned char) c;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			return (i);
		i++;
	}
	return (0);
}

