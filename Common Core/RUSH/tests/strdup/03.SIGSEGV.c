/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_KO_Test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:38:40 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/05 20:54:34 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strdup.h"

int segfault_test_strdup(void)
{
	char *p;
	char *str;

	str = "KKK";
	p = ft_strdup(NULL);
	if (*str == *p)
		return (free(p), 0);
 	return (free(p), -1);
}
