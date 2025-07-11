/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_o_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:50:09 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 15:24:52 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int	o_test(void)
{
	char	*str;
	char	*p;

	p = "onjour";
	str = "Bonjour";
	if (ft_strncmp(ft_strchr(str, 'o'), p, strlen(str)) == 0)
		return (0);
	return (-1);
}
