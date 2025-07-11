/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_SIGBUS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/05 20:54:31 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strdup.h"

int	sigbus_test_strdup(void)
{
	char	*cptr;
	char	*unaligned;
	int		*iptr;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	cptr = malloc(sizeof(int) + 1);
	unaligned = cptr + 1;
	iptr = (int *)unaligned;
	*iptr = 0x12345678;
	ft_strdup(iptr);
	return (0);
}
