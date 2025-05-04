/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:44:01 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/04 13:59:41 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	j;
	size_t	buffer;

	buffer = ft_strlen(dst) + ft_strlen(src);
	dest_len = 0;
	while (dst[dest_len] != '\0')
		dest_len++;
	j = 0;
	while (src[j] != '\0' && dest_len + j + 1 < size)
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	dst[dest_len + j] = '\0';
	return (buffer);
}

/* int	main(void)
{
	char dst[25] = "Hallo, liebe"; //12 + 1
	char src[] = " Freunde";		// 8 + 1

	size_t result = ft_strlcat(dst, src, 16);
	printf("%s:\n", dst);
	printf("Komplette Stringlänge ohne \\0: %zu\n", result);
} */
