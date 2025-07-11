/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_empty_test_strchr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 15:24:12 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int empty_test_strchr(void)
{
	char	*str;
	char	*p;

	p = "";
	str = "";
	if (ft_strncmp(ft_strchr(str, '\0'), p, strlen(str)) == 0)
		return (0);
	return (-1);
}
