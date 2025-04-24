/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:46 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/27 18:06:50 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*ziel;

	if (src == NULL)
		return (NULL);
	ziel = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ziel == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		ziel[i] = src[i];
		i++;
	}
	ziel[i] = '\0';
	return (ziel);
}
/*
int	main(void)
{
	char	*src;
	char	*ziel;

	src = "That string to be copied";
	ziel = ft_strdup(src);
	printf("%s", ziel);
	free(ziel);
}*/
