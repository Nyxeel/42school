/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:37:58 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/13 18:38:00 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
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
	char *src;

	src = "54564654";

	char ergebnis = ft_str_is_numeric(src) + '0';
	write(1, &ergebnis, 1);
}*/
