/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:37:05 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/18 23:50:37 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	odd_routine(t_philo *data)
{

	(void) *data;
	return ;
}

static void	even_routine(t_philo *data)
{

	(void) *data;


	return ;
}

static void	let_him_die(t_philo *data)
{
	(void) *data;

	return ;
}

void	seperate_philos(t_philo *data)
{
	if (data->number_of_philos == 1)
		let_him_die(data);
	else if (data->number_of_philos % 2 == 0)
		even_routine(data);
	else
		odd_routine(data);
}
