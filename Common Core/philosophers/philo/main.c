/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/18 23:51:32 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*get_data(void *arg)
{
	t_philo	*data;

	data = (t_philo *) arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex.wait);
		if (data->count == data->number_of_philos)
		{
			pthread_mutex_unlock(&data->mutex.wait);
			seperate_philos(data);
			break ;
		}
		pthread_mutex_unlock(&data->mutex.wait);
		usleep(10);
	}
	return (NULL);
}

static void	mutex_destroy(t_philo *data)
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
}

bool	start_threads(t_philo *data)
{
	int	i;

	i = 0;
	data->count = 0;

	while (i < data->number_of_philos)
	{
		pthread_mutex_lock(&data->mutex.wait);
		data->count++;
		pthread_mutex_unlock(&data->mutex.wait);
		if (!!pthread_create(&data->philo[i], NULL, get_data, (void *)data))
			return (mutex_destroy(data), false);
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		if (!!pthread_join(data->philo[i], NULL))
			return (mutex_destroy(data), false);
		i++;
	}
	mutex_destroy(data);
	return (true);
}

static void	mutex_init(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_init(&data->mutex.fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex.wait, NULL);
	pthread_mutex_init(&data->mutex.print, NULL);
}

bool	philo_init(t_philo *data, char **av, int ac)
{
	memset(data, 0, sizeof(t_philo));
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_meals = ft_atoi(av[5]);
	data->mutex.fork = ft_calloc(data->number_of_philos,
			sizeof(pthread_mutex_t));
	if (!data->mutex.fork)
		return (false);
	mutex_init(data);
	return (true);
}


int	main(int ac, char **av)
{
	t_philo	data;

	if (ac == 5 || ac == 6)
	{
		if (!input_check(av) || !philo_init(&data, av, ac) || !start_threads(&data))
			return (1); // + CLEANUP für malloc in philo_init
		free(data.mutex.fork);
		return (0);
	}
	printf("WRONG INPUT\n");
	return (0);


// ./philo 4 500 200 200 0    -> valid ??

/*
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

}
