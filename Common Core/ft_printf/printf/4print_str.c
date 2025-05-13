/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4print_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/13 00:42:06 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_counter(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
void	ft_putstr_counter(char *s, int *count)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_counter(s[i], count);
		i++;
	}
}

void	*ft_arg_string(char	*str, int *count)
{
	if (!str)
		return (NULL);
	ft_putstr_counter(str, count);
	return NULL;
}
