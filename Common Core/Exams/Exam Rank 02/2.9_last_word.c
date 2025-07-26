/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.9_last_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/25 11:16:12 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_last_word(char *src)
{
	int		len;
	int		wordend;

	len = ft_strlen(src);
	wordend = len;
	while (src[len - 1] == ' ' || src[len] == '\t')
		len--;
	while (src[len - 1] != ' ' || src[len] == '\t')
		len--;
	while (src[len])
	{
		if (src[len] != ' ')
			write(1, &src[len], 1);
		len++;
	}
}

int	main(int ac, char** av)
{
	if (ac == 2)
		ft_last_word(av[1]);
	write(1, "\n", 1);
}
