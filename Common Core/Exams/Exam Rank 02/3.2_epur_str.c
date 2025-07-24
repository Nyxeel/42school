/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2_epur_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:02:53 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/23 14:23:19 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	epur_str(char *str)
{
	int i = 0;
	int j;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			write(1, &str[i], 1);
		while (str[i + 1] == ' ' || str[i + 1] == '\t')
			i++;
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] > 32)
			write(1, "   ", 3);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
