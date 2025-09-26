/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:37:05 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/26 14:55:59 by netrunner        ###   ########.fr       */
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
	int i = 0;
	int next_id;

	next_id = 1;
	while (!data->stop)
	{
		while (1)
		{
			pthread_mutex_lock(&data->mutex.timestamp);
			if (next_id == data->philo[i].id)
			{
				next_id = (data->philo[i].id % data->number_of_philos) + 1;
				pthread_mutex_unlock(&data->mutex.timestamp);
				break ;
			}
			pthread_mutex_unlock(&data->mutex.timestamp);
			usleep(200);
		}
		print_id(data->philo[i].id, data);
		if (i == data->number_of_philos - 1)
			i = -1;
		i++;
		//print_timestamp(data);
	}
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
