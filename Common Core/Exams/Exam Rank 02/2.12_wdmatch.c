/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.12_wdmatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/23 11:49:52 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		wd_match(char *str, char *str2)
{
	int i, len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && *str2)
	{
		if (str[i] == *str2++)
			i++;
	}
	if (i == len)
		write(1, str, ft_strlen(str));
}

int	main(int ac, char **av)
{
	if (ac == 3)
		wd_match(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
