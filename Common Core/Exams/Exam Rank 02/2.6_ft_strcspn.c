/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.6_ft_strcspn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/01 12:51:06 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strcspn(char *s, char *rejected)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (rejected[j])
		{
			if (s[i] == rejected[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
int	main(int ac, char **av)
{
	if (ac == 4)
		(av[1], av[2][0], av[3]));
	write(1, "\n", 1);
	return (0);
} */
