/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:25:29 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/04 15:38:50 by pjelinek         ###   ########.fr       */
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
	p = (char *)malloc((count + 1) * sizeof(char));
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
	while (index > 0)
	{
		free(freearr[index]);
		index--;
	}
	free(freearr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**split;

	split = (char **)ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
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
				i--;
		}
		i++;
	}
	return (split);
}

/* int	main(void)
{
	char str[] = "Wir haben viel Spas hier zusammen yaaaa juhu!"; // 8 Wörter
	char sep = ' ';
	char **split;

	split = (char **)ft_split(str, sep);
	int i = 0;
	while(split[i])
	{
		printf("**split[%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
} */
