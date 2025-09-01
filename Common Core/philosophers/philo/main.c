/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/01 12:20:04 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


//pthread_mutex_t lock;

void	*print_hello(void *arg)
{
	t_philo *data;

	data = arg;
	//pthread_mutex_lock(&lock);
	int i = 0;
	while (i < 10)
		printf("Hello[%i] from Philo %i\n", i++, data[i].id);
	//pthread_mutex_unlock(&lock);
	return NULL;
}


void	*print_world()
{
	//pthread_mutex_lock(&lock);
	int i = 0;
	while (i < 10)
		printf("World[%i]\n", i++);
	//pthread_mutex_unlock(&lock);
	return NULL;
}

void	start_threads(t_philo *data)
{
	pthread_t	philo[data->number_of_philos];


	//pthread_mutex_init(&lock, NULL);
	//number_of_philo = argv[1];
	for (int i = 0; i < 5; i++)
		pthread_create(&philo[i], NULL, print_hello, (void *)&data);
	for (int i = 0; i < 5; i++)
		pthread_join(philo[i], NULL);

	int i = 0;
	while (i < data->number_of_philos)
		printf("Number of Threads: %i\n", i++);
	//pthread_join(philo[1], NULL);
	//pthread_mutex_destroy(&lock);
}

void	philo_init(t_philo *data, char **av)
{
	/* int i;

	i = 1; */
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->forks = data->number_of_philos;
	/* while (i <= data->number_of_philos)
		philo[i].id = i++; */
}

int	main(int ac, char **av)
{
	t_philo	data;
	
	if (ac == 5 || ac == 6)
	{
		data_init(&data, av);
		start_threads(&data);
	}
	return (0);
	//if (ac <= 6)

/*
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
}
