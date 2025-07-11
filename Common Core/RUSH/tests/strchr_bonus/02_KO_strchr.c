/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_KO_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 17:14:36 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"

int	ko_test_strchr(void)
{
	char	*p;
	char	*str;

	str = "OKOKOK";
	p = ft_strchr("OKOKOK", 'O');
	if (*str != *p)
		return (0);
	return (-1);
}
