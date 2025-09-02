/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 20:01:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static ssize_t	ft_wordcount(char const *str, char c)
{
	size_t	i;
	size_t	words;
	bool	in_word;

	words = 0;
	i = 0;
	in_word = false;
	if (!str)
		return (-1);
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
	int		words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	if (words == -1)
		return (NULL);
	split = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_split_loop(split, s, c));
}

