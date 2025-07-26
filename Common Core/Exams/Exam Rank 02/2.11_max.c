/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.11_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 11:12:31 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		max(int* tab, unsigned int len)
{
	unsigned int 	i;
	int				max;

	i = 0;
	max = tab[i];
	if (len > 0)
	{
		while (i < len)
		{
			if (tab[i] > max)
				max = tab[i];
			i++;
		}
		return (max);
	}
	return (0);
}
int	main()
{
	int	tab[] = {4, 7, 66, 44, 99, 24, 76, 98};
	int	len = 0;
	printf("%i", max(tab, len));
}
