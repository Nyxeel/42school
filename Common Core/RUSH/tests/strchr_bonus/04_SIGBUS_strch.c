/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_SIGBUS_strchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 17:16:22 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"

int	sigbus_test_strchr(void)
{
	char	*cptr;
	char	*unaligned;
	int		*iptr;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	cptr = malloc(sizeof(int) + 1);
	unaligned = cptr + 1;
	iptr = (int *)unaligned;
	*iptr = 0x12345678;
	ft_strchr((char *) iptr, 'c');
	return (0);
}
