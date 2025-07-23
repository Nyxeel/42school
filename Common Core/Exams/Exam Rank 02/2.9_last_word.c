/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.9_last_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/23 09:53:22 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
