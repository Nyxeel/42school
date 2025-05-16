/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4print_str_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:53:12 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/16 19:54:05 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_arg_string(char	*str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
