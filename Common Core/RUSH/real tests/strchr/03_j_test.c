/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_j_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:50:34 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 15:24:58 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int	j_test(void)
{
	char	*str;
	char	*p;

	p = "jour";
	str = "Bonjour";
	if (ft_strncmp(ft_strchr(str, 'j'), p, strlen(str)) == 0)
		return (0);
	return (-1);
}
