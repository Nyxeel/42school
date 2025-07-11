/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_lorem_ipsum_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:50:34 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 12:37:34 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int lorem_ipsum_test(void)
{
	if (ft_strlen("lorem\tipsum\tdolor\nsit\namet\n") == 27 )
		return (0);
	else
		return (-1);
}
