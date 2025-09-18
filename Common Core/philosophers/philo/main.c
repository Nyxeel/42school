/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/18 21:23:03 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void	seperate_philos(t_philo *data)
{
	if

} */
void	print_lock(char *str, t_philo *data)
{
	pthread_mutex_lock(&data->mutex.print);
	printf("%s", str);	//seperate_philos(data);
	pthread_mutex_unlock(&data->mutex.print);

}
void	*get_data(void *arg)
{
	t_philo	*data;
	bool	start;

	start = false;
	data = arg;

	while (1)
	{
		pthread_mutex_lock(&data->mutex.wait);
		if (data->count == data->number_of_philos)
		{
			pthread_mutex_unlock(&data->mutex.wait);
			print_lock("GESCHAFFT\n", data);
			break ;
		}
		pthread_mutex_unlock(&data->mutex.wait);
		usleep(10);
	}
	return (NULL);
}

/* void	*get_data(void *arg)
{
	(void) arg;
	return (NULL);
} */

bool	start_threads(t_philo *data)
{
	int	i;

	i = 0;
	data->count = 0;
	pthread_mutex_init(&data->mutex.wait, NULL);
	pthread_mutex_init(&data->mutex.print, NULL);
	while (i < data->number_of_philos)
	{
		pthread_mutex_lock(&data->mutex.wait);
		data->count++;
		pthread_mutex_unlock(&data->mutex.wait);
		if (!!pthread_create(&data->philo[i], NULL, get_data, (void *)data))
			return (false);
		i++;
	}
/* 	pthread_mutex_lock(&data->mutex.count);
	data->count++;
	pthread_mutex_unlock(&data->mutex.count); */
	i = 0;
	while (i < data->number_of_philos)
	{
		if (!!pthread_join(data->philo[i], NULL))
			return (false);
		i++;
	}
	pthread_mutex_destroy(&data->mutex.wait);
	pthread_mutex_destroy(&data->mutex.print);
	printf("END\n");
	return (true);
}


bool	philo_init(t_philo *data, char **av)
{
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->mutex.fork = ft_calloc(data->number_of_philos,
			sizeof(pthread_mutex_t));
	if (!data->mutex.fork)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_philo	*data;

	data = ft_calloc(1,	sizeof(t_philo));
	if (!data)
		return (false);

	if (ac == 5 || ac == 6)
	{
		if (!input_check(av) || !philo_init(data, av) || !start_threads(data))
			return (1); // + CLEANUP für malloc in philo_init
		free(data->mutex.fork);
		free(data);
	}
	return (0);
	//if (ac <= 6)

/*
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
}
