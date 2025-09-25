/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:52:19 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/25 21:08:36 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_timestamp(t_data *data)
{
	long long	timestamp;
	long long	time;

	pthread_mutex_lock(&data->mutex.timestamp);
	timestamp = gettime();
	pthread_mutex_unlock(&data->mutex.timestamp);

	usleep(20000);
	time = gettime() - timestamp;

	print_time(time, data);
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
	int			i;
	long long	start_time_ms;

	i = 0;
	pthread_mutex_lock(&data->mutex.timestamp);
	start_time_ms = gettime();
	while (i < data->number_of_philos)
	{
		data->philo[i].last_meal = start_time_ms;
		i++;
	}
	data->start = true;
	pthread_mutex_unlock(&data->mutex.timestamp);
	print_string("Start_Time : ", data);
	print_time(start_time_ms, data);
}
