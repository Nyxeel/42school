/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.9_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/24 14:51:06 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	iscapital(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	first_letter(char c, char space)
{
	if ((c >= 97 && c <= 122) && (space <= 32))
		return (1);
	return (0);
}

void	str_capitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (iscapital(str[i]))
			str[i] = str[i] + 32;
		if (first_letter(str[i], str[i - 1]))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char** av)
{
	int i;

	i = 1;
	if (ac == 1)
		write(1, "\n", 1);
	else
		while (i < ac)
		{
			str_capitalize(av[i]);
			i++;
		}
}


