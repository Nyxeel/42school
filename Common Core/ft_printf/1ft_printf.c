/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:05:14 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/12 13:06:39 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;

	if (!str)
		return (0);
	va_start(ap, str);
	result = ft_va_start(str, ap);
	va_end(ap);
	return (result);
}
