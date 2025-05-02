/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:38:28 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 15:16:30 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;   
    unsigned char *ziel;
	const unsigned char *quelle;
	
	ziel = (unsigned char *) dest;
	quelle = (const unsigned char *) src;
	if (!ziel || !quelle)
		return (NULL);
	i = 0;
    while (i < n)
    {
        ziel[i] = quelle[i];
        i++;
    }
    return (dest);
}

int main(void)
{
	char *dest[35];
	char src[] = "";
	char *p;

	printf("%lu\n", sizeof(src)/sizeof(src[0]));
	p = ft_memcpy(dest, &src[0], 33);
	printf("%s", p);
}