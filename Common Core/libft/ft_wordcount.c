/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/14 18:34:32 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *str, char c)
{
	size_t	i;
	size_t	words;
	bool	in_word;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
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
