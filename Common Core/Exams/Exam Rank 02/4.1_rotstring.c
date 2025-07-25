/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1_rotstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/25 09:44:47 by netrunner        ###   ########.fr       */
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

int	ft_isspace(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	wordcount(char c, char space)
{
	if ((c >= 97 && c <= 122) && (space <= 32))
		return (1);
	return (0);
}

void	rotstring(char *str)
{
	int i;
	int start;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	start = i;
	while (str[i])
	{
		while (str[i] && !ft_isspace(str[i]))
			i++;
		while (str[i] && ft_isspace(str[i]))
			i++;	
		while ((str[i] && !ft_isspace(str[i])) && !ft_isspace(str[i + 1]))
		{
			while (str[i] && !ft_isspace(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
		}
	}
	while (str[start] && !ft_isspace(str[start]))
	{
		write(1, &str[start], 1);
		start++;
	}


		//printf("Wordlen: %i", start - i);
}

int	main(int ac, char** av)
{
	int i;

	i = 1;
	if (ac == 2)
		rotstring(av[1]);
	write(1, "\n", 1);

}


