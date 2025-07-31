/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.4_rev_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/31 10:40:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

// You hate people! But I love gatherings. Isn't it ironic?


void	rev_wstr(char *str)
{
	int	end;
	int	start;

	if (!str)
		return ;
	end = ft_strlen(str) - 1;
	while (end >= 0)
	{
		start = end;
		while (start >= 0 && !ft_isspace(str[start]))
			start--;
		write(1, &str[start + 1], end - start);
		end = start - 1;
		if (end >= 0)
			write(1, " ", 1);
	}
}


int	main(int ac, char** av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);

}


