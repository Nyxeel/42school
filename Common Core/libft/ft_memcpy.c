/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:38:28 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/09 13:30:14 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ziel;
	unsigned char		*quelle;

	if (n == 0)
		return (dest);
	if (dest == NULL || src == NULL)
		return (NULL);
	ziel = (unsigned char *) dest;
	quelle = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ziel[i] = quelle[i];
		i++;
	}
	return ((void *)dest);
}


int	main(void)
{
	char *p;

	p = ft_memcpy(NULL, NULL, 0);

	printf("%s", p);
/* 	char *c = memcpy("ERROR", "hi how are you", 5);
	printf("%s", c); */
}
