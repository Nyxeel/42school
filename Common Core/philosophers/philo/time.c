/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:52:19 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/25 20:03:02 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_timestamp(t_data *data)
{
	pthread_mutex_lock(&data->mutex.print);
	data->start_time_ms = gettime();
	usleep(20000);
	data->timestamp = gettime() - data->start_time_ms;
	printf("Zeit in ms: %lld\n", data->timestamp);
	pthread_mutex_unlock(&data->mutex.print);
}

long long	gettime(void)
{
	struct timeval	time;
	long long		t1;
	long long		t2;

	gettimeofday(&time, NULL);
	t1 = (long long)time.tv_sec * 1000;
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
	printf("START_TIME ms: %lld\n", data->start_time_ms);
	data->start = true;
	pthread_mutex_unlock(&data->mutex.start_time);
}
