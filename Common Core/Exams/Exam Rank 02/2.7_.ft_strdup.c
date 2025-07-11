/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.7_.ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/09 13:51:55 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src); 
	dup = malloc(len + 1 * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];			/////		AUFPASSEN
		i++;
	}
	dup[i] = 0;						/////		not i + 1 !!
	return (dup);
}

int	main()
{
	char	p[] = "Hallo Welt";
	printf("%s", ft_strdup(p));
}
