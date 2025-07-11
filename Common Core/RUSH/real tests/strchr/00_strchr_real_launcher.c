/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strchr_real_launcher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:08:15 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/06 15:24:04 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int strchr_real_launcher(void)
{
	t_stack	*list;
	int		result;

	list = calloc(1, sizeof(t_stack));
	if (!list)
		return (-1);
	list->size = 0;
	list->routine = "STRCHR";
	load_test(list, "b in Bonjour", &b_test, false);
	load_test(list, "o in Bonjour", &o_test, false);
	load_test(list, "j in Bonjour", &j_test, false);
	load_test(list, "s in Bonjour", &s_test, false);
	load_test(list, "\\0 in empty string", &empty_test_strchr, false);
	result = launch_tests(list);
	return(result);
}
