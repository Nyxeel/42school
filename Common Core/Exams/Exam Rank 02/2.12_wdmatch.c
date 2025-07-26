/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.12_wdmatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 11:21:41 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$ */


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
		write(1, str, len);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		wd_match(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
