/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.3_alpha_mirror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 11:14:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$> */


#include <unistd.h>

void	ft_alpha_mirror(char *str, char *str2)
{
	int i = 0;
	int j;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' - str[i] + 'A';
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - str[i] + 'a';
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_alpha_mirror(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
