/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:25:29 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/15 14:35:20 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if ((s[i - 1] != c && s[i] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
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

static void	ft_freeall(char **freearr, size_t index)
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

char	**ft_split_loop(char **split, char const *s, char c)
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

/* int	main(void)
{
	char **split;
	int i = 0;

	split = (char **)ft_split("lorem ipsum dolor sit amet, mmn, mi. ", ' ');

	if (!split)
		return (0);
	while(split[i])
	{
		printf("**split[%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
} */
