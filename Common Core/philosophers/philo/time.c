/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:52:19 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/25 01:02:23 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_timestamp(t_data *data)
{
	pthread_mutex_lock(&data->mutex.timestamp);
	data->timestamp = gettime() - data->start_time_ms;
	printf("Zeit in ms: %ld\n", data->timestamp);
	pthread_mutex_unlock(&data->mutex.timestamp);
}

int64_t	gettime(void)
{
	struct timeval	time;
	int64_t			t1;
	int64_t			t2;

	gettimeofday(&time, NULL);
	t1 = (int64_t)(time.tv_sec) * 1000;
	t2 = (time.tv_usec / 1000);
	return (t1 + t2);
}

void	set_starttime(t_data *data)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&data->mutex.start_time);
	data->start_time_ms = gettime();
	while (i < data->number_of_philos)
	{
		data->philo[i].last_meal = data->start_time_ms;
		i++;
	}
	printf("ZEIT in Jahren: %ld\n", data->philo[0].last_meal / 60 / 60 / 24 / 365 / 1000);
	printf("ZEIT in Tagen: %ld\n", data->philo[0].last_meal / 60 / 60 / 24 /1000);
	printf("ZEIT in MiliSek: %ld\n", data->philo[0].last_meal);
	data->start = true;
	pthread_mutex_unlock(&data->mutex.start_time);
}