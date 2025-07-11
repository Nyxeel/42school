/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.8_.ft_strrev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/09 13:54:49 by pjelinek         ###   ########.fr       */
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

char    *ft_strrev(char *src)
{
	int		len;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	while (src[len])
	{
		
	}
	return (dup);
}

int	main()
{
	char	p[] = "Hallo Welt";
	printf("%s", ft_strrev(p));
}
