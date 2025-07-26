/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 17:50:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
 */

#include <unistd.h>

void	ft_inter(char *str, char *str2)
{
	int i = 0;
	int j = 0;
	int lookup[256] = {0};

	while (str[i])
	{
		
		while (str2[j])
		{
			if (str[i] == str2[j] && !lookup[(int)str2[j]])
			{
				write(1, &str[i], 1);
				lookup[(int) str2[j]] = 1;
				break;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
