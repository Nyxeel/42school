/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1_rotstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/31 11:23:40 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
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
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i])
	{
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


