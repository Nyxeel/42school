/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:11:44 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/18 20:13:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (*str == 0)
	{
		return (1);
	}
	while (*str)
	{
		if (*str < 32 || *str > 126)
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
    
    src = "fsdfdsf";
    
    char ergebnis = ft_str_is_printable(src) + '0';
	write(1, &ergebnis, 1);
	
}*/
