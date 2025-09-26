/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:37:05 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/26 22:54:16 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	odd_routine(t_data *data)
{

	(void) data;
	return ;
}

/*
static void	sorting_ids(t_data *data)
{
	//print_timestamp(data);

	(void ) data;
	int i = 0;
	int next_id;

	next_id = 1;
	while (!data->stop)
	{
		while (!data->stop)
		{
			pthread_mutex_lock(&data->mutex.wait);
			if (next_id == data->philo[i].id)
			{
				next_id = (data->philo[i].id % data->number_of_philos) + 1;
				pthread_mutex_unlock(&data->mutex.wait);
				break ;
			}
			pthread_mutex_unlock(&data->mutex.wait);
			usleep(200);
		}
		print_id(data->philo[i].id, data);
		pthread_mutex_lock(&data->mutex.wait);
		if (i == data->number_of_philos - 1)
		{
			next_id = 1;
			i = -1;
		}
		i++;
		pthread_mutex_unlock(&data->mutex.wait);

		print_timestamp(data);
	}
	return ;
}*/

int	set_state(t_data *data)
{

	if (data->id % 2 == EVEN)
	{

		return (WAITING);
	}
	else
	{

		return (EATING);
	}
}

static void	even_routine(t_data *data)
{
	t_philo	*philo;


	philo = data->philo;
	pthread_mutex_lock(&data->mutex.wait);
	philo[data->id].state = set_state(data);
	printf("philo[%i].state: %i\n", data->id, philo[data->id].state);
	data->id += 1;
	pthread_mutex_unlock(&data->mutex.wait);

	/* pthread_mutex_lock(&data->mutex.print);
	pthread_mutex_unlock(&data->mutex.print); */


	/* i = 1;
	while (i <= data->number_of_philos)
	{
		pthread_mutex_lock(&data->mutex.print);
		printf("philo[%i].state: %i\n", i, philo[i].state);
		pthread_mutex_unlock(&data->mutex.print);
		i++;
	}
	printf("___________\n"); */

	/* while (!data->stop)
	{
		if (state == EATING)
			take_forks(data);
		if (state == SLEEPING)
			send_sleep();
			usleep(data->time_to_sleep);
		if (state == THINKING)
			print_thinking(data);
		if (state == WAITING)
			usleep(data->time_to_eat);
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


