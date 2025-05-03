/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:29:00 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 21:56:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ziel;
	unsigned char	*quelle;

	ziel = (unsigned char *) dest;
	quelle = (unsigned char *) src;
	printf("%d\n", (*ziel > *quelle));
	if (ziel > quelle)
	{
		while (n--)
			*ziel++ = *quelle++;
	}
	else
	{
		ziel += n;
		quelle += n;
		while (n--)
		{
			*(--ziel) = *(--quelle);

		}
	}
	return (dest);
}

int	main(void)
{
	char array[] = "ABCDEFGHIJKLMNO";
	char arr[] = "ABCDEFGHIJKLMNO";

	char *p = ft_memmove(&arr[0], &arr[12], 16);
	printf("%s\n\n", p);
	char *s = memmove(&array[0], &array[12], 16);
	printf("%s\n\n", s);
}
