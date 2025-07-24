/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.8_rstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/24 14:51:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* void	print_hex(int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb > 16)
		print_hex(nb / 16);
	write(1, &base[nb % 16], 1);
}

int	isspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
} */


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	iscapital(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	last_letter(char c, char space)
{
	if ((c >= 97 && c <= 122) && space <= 32)
		return (1);
	return (0);
}

char	*rstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (iscapital(str[i]))
			str[i] = str[i] + 32;
		if (last_letter(str[i], str[i + 1]))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
	return (str);
}

int	main(int ac, char** av)
{
	if (ac == 2)
		rstr(av[1]);
	write(1, "\n", 1);
}


