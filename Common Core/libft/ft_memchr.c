/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:28:24 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 14:59:29 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		letter;
	size_t				i;

	str = s;
	letter = (unsigned char) c;
	i = 0;
	if (str == NULL)
		return (NULL);
	if (letter == 0)
		return ((char *)str);
	while (i < n)
	{
		if (str == letter)
			return ((unsigned char *) str);
		i++;
	}
	return (NULL);
}
