/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_SIGSEGV_strlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:50:34 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 02:31:57 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int segfault_test_strlen(void)
{
	char	*cptr;
	char	*unaligned;
	int		*iptr;
	
	cptr = malloc(sizeof(int) + 1);
	unaligned = cptr + 1;
	iptr = (int *)unaligned;
	*iptr = 0x12345678;
	if (ft_strlen(NULL))
		return (0);
	else
		return (-1);
}
