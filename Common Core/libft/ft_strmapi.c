/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:51:00 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 22:57:22 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	manipulate(unsigned int index, char c)
{
	if (index % 2 == 0)
		return ('*');
	return (c);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*hidden;
	unsigned int	i;

	i = 0;
	hidden = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!hidden)
		return (NULL);
	while (s[i])
	{
		hidden[i] = f(i, s[i]);
		i++;
	}
	hidden[i] = '\0';
	return (hidden);
}
/*
int	main(void)
{
	char const s[] = "";
	char *new;

	new = ft_strmapi(s, manipulate);
	printf("%s\n", new);
	free(new);
} */
