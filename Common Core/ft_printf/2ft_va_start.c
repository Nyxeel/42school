/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_va_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:43:03 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/10 19:57:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int	ft_va_start(const char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (is_valid(str[i + 1]))
				count += print_arg(str[i + 1], ap);
			else
				(write(1, &str[i + 1], 1), count += 1);
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
			(count += 1, i++);
	}
	return (count);
}
