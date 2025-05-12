/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3find_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/12 17:30:50 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (write(1, (char[]){va_arg(ap, int)}, 1));
	if (c == 's')
		return (ft_arg_string(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_arg_int(va_arg(ap, int)));
	if (c == 'u')
		return (ft_arg_unsigned(va_arg(ap, unsigned int)));
	if (c == '%')
		return (write(1, &c, 1));
	if (c == 'x' || c == 'X')
		return (ft_hexa_base((va_arg(ap, unsigned int)), c, 0));
	if (c == 'p')
		return (ft_arg_pointer(va_arg(ap, void *)));
	else
		return (0);
}
