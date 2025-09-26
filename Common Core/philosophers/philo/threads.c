/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/26 20:06:57 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void	print_death(void)
{
	return ;
}
*/

static void	*start_monitoring(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *) arg;
	i = 0;
	usleep(data->time_to_die / 2);
	while (!data->stop)
	{
		pthread_mutex_lock(&data->mutex.timestamp);
		if (gettime() - data->philo[i].last_meal > data->time_to_die)
		{
			pthread_mutex_unlock(&data->mutex.timestamp);
			print_string("Philo has died ", data);
			print_timestamp(data);
			data->stop = true;
			break ;
		}
		if (i == data->number_of_philos - 1)
			i = -1;
		i++;
		pthread_mutex_unlock(&data->mutex.timestamp);
		usleep(10);
	}
	return (NULL);
}

static void	*get_started(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (!data->stop)
	{
		pthread_mutex_lock(&data->mutex.timestamp);
		if (data->start == true)
		{
			pthread_mutex_unlock(&data->mutex.timestamp);
			seperate_philos(data);
			break ;
		}
		pthread_mutex_unlock(&data->mutex.timestamp);
		usleep(10);
	}
	return (NULL);
}

static bool	join_the_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (!!pthread_join(data->philo[i].thread, NULL))
			return (false);
		i++;
	}
	if (!!pthread_join(data->monitor, NULL))
		return (false);
	return (true);
}

bool	start_threads(t_data *data)
{
	int			i;

	i = 0;
	if (!mutex_init(data))
		return (false);
	while (i < data->number_of_philos)
	{
		if (!!pthread_create(&data->philo[i].thread, NULL, get_started,
				(void *)data))
		{
			data->stop = true;
			return (thread_cleanup(&data->philo->thread, i),
				mutex_destroy(data), false);
		}
		i++;
	}
	set_starttime(data);


	i = 0;
	while (i < data->number_of_philos)
	{
		printf("Lastmeal[%i]: %lli\n", i, data->philo[i].last_meal);
		i++;
	}


	if (!!pthread_create(&data->monitor, NULL, start_monitoring, (void *)data))
		return (mutex_destroy(data), false);
	if (!join_the_threads(data))
		return (mutex_destroy(data), false);
	mutex_destroy(data);
	return (true);
}
