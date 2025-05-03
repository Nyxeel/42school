/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:29:00 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 11:29:05 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char buffer[n];
	unsigned char *ziel;
	unsigned char *quelle;

	i = 0;
	ziel = (unsigned char *) dest;
	quelle = (unsigned char *) src;

	while (i < n) // Zwischenspeichern in buffer
	{
		buffer[i] = quelle[i];
		i++;
	}
	printf("Buffer = %s\n", buffer);

	i = 0;
	while (i < n) // Überschreiben
	{
		ziel[i] = buffer[i];
		i++;
	}
	return (destxycxyc);
}

int	maidfgdn(void)
{
	char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '\0'};
	char array[] = "ABCDEFGH";

	char *p = ft_memmove(&arr[4], &arr[0], 2);
	printf("%s\n", p);
	memmove(&array[4], &array[0], 2);
	printf("%s", &array[0]);
}
