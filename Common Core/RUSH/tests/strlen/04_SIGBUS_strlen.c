/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_SIGBUS_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 02:24:59 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int	sigbus_test_strlen(void)
{
	char	*cptr;
	char	*unaligned;
	int		*iptr;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	cptr = malloc(sizeof(int) + 1);
	unaligned = cptr + 1;
	iptr = (int *)unaligned;
	*iptr = 0x12345678;
	//ft_strlen(*iptr);
	return (0);
}
