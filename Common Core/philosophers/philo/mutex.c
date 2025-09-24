/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/25 00:50:12 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_lock(char *str, t_data *data)
{
	pthread_mutex_lock(&data->mutex.print);
	printf("%s", str);
	pthread_mutex_unlock(&data->mutex.print);
}

void	mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&data->mutex.fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex.wait);
	pthread_mutex_destroy(&data->mutex.print);
	pthread_mutex_destroy(&data->mutex.start_time);
	pthread_mutex_destroy(&data->mutex.timestamp);


	///
	///
	/// Ev. noch weitere Mutex destroyen!!
}

bool	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (!!pthread_mutex_init(&data->mutex.fork[i], NULL))
			return (mutex_cleanup(data->mutex.fork, i, data), false);
		i++;
	}
	if (!!pthread_mutex_init(&data->mutex.wait, NULL))
		return (mutex_cleanup(data->mutex.fork, i, data), false);
	data->mutex.wait_ok = true;
	if (!!pthread_mutex_init(&data->mutex.print, NULL))
		return (mutex_cleanup(data->mutex.fork, i, data), false);
	data->mutex.print_ok = true;
	if (!!pthread_mutex_init(&data->mutex.start_time, NULL))
		return (mutex_cleanup(data->mutex.fork, i, data), false);
	data->mutex.start_time_ok = true;
	data->mutex.print_ok = true;
	if (!!pthread_mutex_init(&data->mutex.timestamp, NULL))
		return (mutex_cleanup(data->mutex.fork, i, data), false);
	data->mutex.timestamp_ok = true;

	///
	///
	/// Ev. noch weitere Mutex initen!!


	return (true);
}
