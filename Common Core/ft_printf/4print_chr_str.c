/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4print_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/11 13:47:13 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int	ft_arg_char(char c, va_list ap)
{
	c = va_arg(ap, int);
	return (1 + write(1, &c, 1))
}

int	ft_arg_string(char	*str, va_list ap)
{
	str = va_arg(ap, char *);
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

/* if (c == 'x' || c == 'X')
		write(1, "--HexDez--", 10);
	return (10);
}

if (c == 'p')

{
	write(1, "xXPointerXx", 11);
	return (11);
} */
