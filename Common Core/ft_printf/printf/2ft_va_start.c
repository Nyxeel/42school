/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_va_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:43:03 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/12 17:42:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_va_start(const char *str, va_list ap)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
				count += find_arg(str[i + 1], ap);
			else
				return (-1);
			i += 2;
		}
		if (str[i] && write(1, &str[i], 1))
		{
			i++;
			count += 1;
		}
	}
	return (count);
}
