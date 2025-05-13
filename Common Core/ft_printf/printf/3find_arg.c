/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3find_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/13 10:17:15 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	find_arg(char c, va_list ap, int *count)
{
	if (c == 'c')
		ft_putchar_counter(va_arg(ap, int), count);
	if (c == 's')
		ft_arg_string(va_arg(ap, char *), count);
	if (c == 'd' || c == 'i')
		ft_int_check(va_arg(ap, int), count);
	if (c == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), 10, count, 'z');
	if (c == 'p')
		ft_arg_pointer(va_arg(ap, void *), count, c);
	if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), 16, count, c);
	if (c == '%')
		ft_putchar_counter(c, count);
}
