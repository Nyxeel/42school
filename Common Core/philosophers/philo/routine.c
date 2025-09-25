/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:37:05 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/25 03:29:59 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	odd_routine(t_data *data)
{

	(void) *data;
	return ;
}

static void	even_routine(t_data *data)
{
	(void) *data;

/*	int i = 1;
	
	 while (i != 0)
	{	
		data->start_time_ms = gettime();
		usleep(20000);
		print_timestamp(data);
		i -= 1;
	} */
	return ;
}

static void	let_him_die(t_data *data)
{
	(void) *data;

	return ;
}

void	seperate_philos(t_data *data)
{
	if (data->number_of_philos == 1)
		let_him_die(data);
	else if (data->number_of_philos % 2 == 0)
		even_routine(data);
	else
		odd_routine(data);
}

void	set_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		data->philo[i].ri_fork = i;
		if (data->number_of_philos > 1) // 1 Philo cant pick up a second fork!
			data->philo[i].le_fork = i + 1 % data->number_of_philos;
		data->philo[i].id = i + 1;
		//data->philo[i].last_meal =
		i++;
	}
}
