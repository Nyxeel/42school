/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_testLab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/06 15:55:20 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_doubles(char *str, int c)
{
	unsigned char	letter;
	unsigned int	count;
	size_t			i;

	letter = (unsigned char) c;
	count = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			count++;
		i++;
	}
	return (count);
}
int main()
{
	char str[] = "1000000P000000010000000000001";
	printf("%i", find_doubles(str, 'P'));
}
