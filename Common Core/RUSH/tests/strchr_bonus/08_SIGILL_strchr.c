/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_SIGILL_strchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 18:18:00 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"

int sigill_test_strchr(void)
{
   __asm__("ud2"); // 'ud2' ist auf x86 eine garantiert ungültige Instruktion
	return (-1);
}
