/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.8_.ft_strrev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/04 14:12:24 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */


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
	char	tmp;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	while (i < len - 1)
	{
		tmp = src[i];
		src[i] = src[len - 1];
		src[len - 1] = tmp;
		i++;
		len--;
	}
	return (src);
}

int	main()
{
	char	p[] = "Willkommen in der neuen Welt";
	printf("%s", ft_strrev(p));
}
