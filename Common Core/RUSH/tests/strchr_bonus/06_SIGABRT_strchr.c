/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_SIGABRT_strchr copy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 18:41:26 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"

int sigabrt_test_strchr(void)
{
	ft_strchr("CEASER", 'c');
    abort();
    return (0);
}
