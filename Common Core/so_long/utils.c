/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/15 21:39:03 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeall(char **freearr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(freearr[i]);
		i++;
	}
	free(freearr);
}

int	ft_strcheck(const char *str, int c)
{
	unsigned char	letter;
	int				i;

	i = 0;
	letter = (unsigned char) c;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			i++;
		else
			return (0);
	}
	return (1);
}



int	count_letters(char *str, int c)
{
	unsigned char	letter;
	unsigned int	count;
	size_t			i;

	letter = (unsigned char) c;
	count = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			count++;
		i++;
	}
	return (count);
}

int	find_char(char *str, int c)
{
	unsigned char	letter;
	size_t			i;

	letter = (unsigned char) c;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == letter)
			return (i);
		i++;
	}
	return (0);
}

int	count_lines(char **split)
{
	int	count;

	count = 0;
	if (split || *split)
	{
		while (split[count] != NULL)
			count++;
	}
	return (count);
}


