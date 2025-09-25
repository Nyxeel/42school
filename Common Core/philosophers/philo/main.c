/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/25 19:40:44 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philo_init(t_data *data, char **av, int ac)
{
	memset(data, 0, sizeof(t_data));
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_meals = ft_atoi(av[5]);
	data->philo = ft_calloc(data->number_of_philos,
			sizeof(t_philo));
	if (!data->philo)
		return (false);
	data->mutex.fork = ft_calloc(data->number_of_philos,
			sizeof(pthread_mutex_t));
	if (!data->mutex.fork)
		return (cleanup(data), false);
	set_philo(data);


	/*data->philo->thread = ft_calloc(data->number_of_philos,
			sizeof(pthread_t));
	if (!data->philo->thread)
		return (cleanup(data), false); */

	return (true);
}


int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!input_check(av))
			return (1);
		if (!philo_init(&data, av, ac) || !start_threads(&data))
			return (cleanup(&data), 1);
		cleanup(&data);
		return (0);
	}
	printf("WRONG INPUT\n");
	return (0);
}

// ./philo 4 500 200 200 0    -> valid ??

/*
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

