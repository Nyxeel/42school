/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:43:35 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/13 18:43:36 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	if (*str == 0)
	{
		return (1);
	}
	while (*str)
	{
		if (*str < 97 || *str > 122)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*src;

	src = "sdfd5sdfsdf";

	char ergebnis = ft_str_is_lowercase(src) + '0';
	write(1, &ergebnis, 1);
}*/
