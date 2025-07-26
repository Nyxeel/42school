/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2_sort_in_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/25 11:01:50 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int tmp;

	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

/*
int	main()
{
	int tab[]= {5, 1, 7, 254, 134, 7, 99, 0};
	int size = (sizeof(tab) / sizeof(int));
	sort_int_tab(tab, size);
	printf("SIZE:%i\n", size);
	int i = 0;
	while (i < size)
	{
		printf("%i\n", tab[i]);
		i++;
	}
} */



