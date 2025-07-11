/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strdup_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:48:14 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/05 22:48:18 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strdup.h"

int strdup_launcher(void)
{
	t_unit_test	*testlist;

	testlist = malloc(sizeof(t_unit_test));
	if (!testlist)
		return (-1);
	testlist->size = 0;
	testlist->func_name = "STRDUP";
	testlist->list = malloc(sizeof(t_list));
	if (!testlist->list)
		return (-1);
	load_test(&testlist, "Basic test", &ok_test_strdup);
	load_test(&testlist, "NULL test", &ko_test_strdup);
	load_test(&testlist, "Bigger string test", &segfault_test_strdup);
	load_test(&testlist, "Bigger string test", &sigbus_test_strdup);
	return(launch_tests(&testlist));
}
