/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4print_str_p_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/12 13:16:20 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int	ft_count_hexa(size_t hexanum)
{
	int	digits;

	digits = 0;
	while (hexanum > 0)
	{
		hexanum = hexanum / 16;
		digits++;
	}
	return (digits);
}

int	ft_hexa_base(size_t hexanum, char Xx, int count)
{
	char	*base;
	size_t	hexalen;

	hexalen = ft_count_hexa(hexanum);
	if (Xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (hexanum >= 16)
	{
		ft_hexa_base((hexanum / 16), Xx, count);
		write(1, &base[hexanum % 16], 1);
	}
	if (hexanum < 16)
		(write(1, &base[hexanum % 16], 1));
	return (hexalen);
}

int	ft_arg_pointer(void *p)
{
	size_t	hexanum;

	if (!p)
		return (write(1, "(nil)", 5));
	hexanum = (size_t) p;
	return ((write(1, "0x", 2) + ft_hexa_base(hexanum, 'p', 0)));
}

int	ft_arg_string(char	*str)
{
	if (!str)
		return (-1);
	return (write(1, str, ft_strlen(str)));
}
