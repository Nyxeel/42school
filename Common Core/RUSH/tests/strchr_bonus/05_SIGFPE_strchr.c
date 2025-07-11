/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_SIGFPE_strchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 17:28:30 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"

int	sigfpe_test_strchr(void)
{
	char	*cptr;
	int 	zero;

	zero = 0;
	cptr = malloc((sizeof(int) + 1) / zero);
	cptr = (char *) NULL; 
	ft_strchr(cptr, 'c');
	return (0);
}
