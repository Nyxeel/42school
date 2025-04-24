/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:20:33 by mchoma            #+#    #+#             */
/*   Updated: 2025/02/23 22:56:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_error(int c);

int	lenght(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != 0)
		counter ++;
	return (counter);
}

int	helper(char **dest, char *add, int len)
{
	int		counter;
	char	*fin;

	counter = 0;
	len = len + lenght(*dest);
	fin = malloc (sizeof (char) *(len + 1));
	if (fin == 0)
	{
		ft_error(1);
		return (0);
	}
	len = lenght(*dest);
	while ((*dest)[counter] != 0)
	{
		fin[counter] = (*dest)[counter];
		counter ++;
	}
	counter = 0;
	while (add[counter] != 0)
	{
		fin[counter + len] = add[counter];
		counter ++;
	}
	fin[counter + len] = 0;
	free(*dest);
	*dest = fin;
	return (1);
}

int	append(char **dest, char *add)
{
	int		counter;
	char	*fin;
	int		len;

	len = lenght(add);
	counter = 0;
	if (**dest == 0)
	{
		fin = malloc(sizeof(char) * (len + 1));
		if (fin == 0)
		{
			ft_error(1);
			return (0);
		}
		while (add[counter] != 0)
		{
			fin[counter] = add[counter];
			counter ++;
		}
		fin[counter] = 0;
		free(*dest);
		*dest = fin;
		return (-1);
	}
	helper(dest, add, len);
	return (1);
}
