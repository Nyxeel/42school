/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:36:36 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 14:55:03 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *) s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	return (s);
}

/* int main(void)
{
    int arr[] = {25, 25, 26, 25};


    ft_bzero(arr, sizeof(arr));
	for (unsigned long int i = 0; i < 7; i++)
        printf("arr[%lu] = %d\n", i, arr[i]);

} */
