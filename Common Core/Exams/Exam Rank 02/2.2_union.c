/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.2_union.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/09 00:38:39 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *str, char *str2)
{
	int i = 0;
	int j;
	char lookup[256] = {0};

	while (str[i])
		lookup[(int)str[i++]] = 1;
	i = 0;
	while (str2[i])
		lookup[(int)str2[i++]] = 1;
	i = 0;
	while (str[i])
	{
		if (lookup[str[i]] == 1)
		{
			write(1, &str[i], 1);
			lookup[(int)str[i]] = 0;
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (lookup[str2[i]] == 1)
		{
			write(1, &str2[i], 1);
			lookup[(int)str2[i]] = 0;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}