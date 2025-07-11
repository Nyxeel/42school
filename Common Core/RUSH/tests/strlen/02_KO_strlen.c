/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_KO_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:50:09 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 02:22:46 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int ko_test_strlen(void)
{
	if (ft_strlen("THIS IS A VERY VERY LONG STRONG WHICH IS TOO LONG") == 35)
		return (0);
	else
		return (-1);
}
