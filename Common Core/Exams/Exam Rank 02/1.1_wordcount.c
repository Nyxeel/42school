/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1_wordcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/31 09:54:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>


int	ft_isspace(char c)
{
	if (c == ' ' || c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	ft_wordcount(char *str)
{
	int i;
	int words;
	bool in_word;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			in_word = false;
		else if (!in_word)
		{
			in_word = true;
			words++;
		}
		i++;
	}
	return (words);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("Words: %i", ft_wordcount(av[1]));
	return (0);
}
