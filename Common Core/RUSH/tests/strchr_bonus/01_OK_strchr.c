/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_OK_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 17:14:55 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"
#include <stdio.h>
#include <unistd.h>

int	ok_test_strchr(void)
{
	char	*p;
	char	*str;

	str = "s is the string";
	p = ft_strchr("this is the string", 's');
	if (*str == *p)
		return (0);
	return (-1);
}
