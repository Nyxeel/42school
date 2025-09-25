/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/25 16:37:30 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void	print_death(void)
{
	return ;
}

static void	*start_monitoring(void *arg)
{
	t_data	*monitoring;
	int 	i;
	int64_t time_to_die;

	i = 0;
	monitoring = (t_data *) arg;
	time_to_die = monitoring->time_to_die;
	usleep(monitoring->time_to_die / 2);
	while (!monitoring->stop)
	{
		if (gettime() - monitoring->philo[i].last_meal >= time_to_die)
		{
			print_death();
			break ;
		}
		if (i == monitoring->number_of_philos - 1)
			i = -1;
		i++;	
		usleep(10);
	}
	return (NULL);
} */

static void	*get_started(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (!data->stop)
	{
		pthread_mutex_lock(&data->mutex.start_time);
		if (data->start == true)
		{
			pthread_mutex_unlock(&data->mutex.start_time);
			seperate_philos(data);
			break ;
		}
		pthread_mutex_unlock(&data->mutex.start_time);
		usleep(10);
	}
	return (malloc(0));
}

static bool	join_the_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (!!pthread_join(data->philo[i].thread, NULL))
			return (mutex_destroy(data), false);
		i++;
	}
	mutex_destroy(data);
	return (true);
}

bool	start_threads(t_data *data)
{
	int	i;

	i = 0;
	data->count = 0;
	if (!mutex_init(data))
		return (false);
/* 	if (!!pthread_create(&data->monitor, NULL, start_monitoring, (void *)data))
			return (mutex_destroy(data), false); */
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
	if (!join_the_threads(data))
		return (false);
	return (true);
}