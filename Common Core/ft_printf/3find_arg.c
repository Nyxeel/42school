/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3find_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/10 19:57:14 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_arg_char(c, ap));
	if (c == 's')
		return (ft_arg_string((char *) c), ap);
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_arg_int(0, ap));
	if (c == 'x' || c == 'X')
		return (ft_arg_hexa(c, ap));
	if (c == 'p')
		return (ft_arg_pointer((char *) c, ap));
	else
		return (0);
}
