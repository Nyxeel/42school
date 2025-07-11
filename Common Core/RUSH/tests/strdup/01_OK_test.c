/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_OK_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:38:40 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/05 21:10:30 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strdup.h"

int ok_test_strdup(void)
{
	char *p;
	char *str;

	str = "OK";
	p = ft_strdup("OK");
	if (*str == *p)
		return (free(p), 0);
 	return (-1);
}
