/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/31 17:30:31 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


//pthread_mutex_t lock;

void	*philo(void *arg)
{
	//pthread_mutex_lock(&lock);
	int i = 0;
	while (i < 10)
		printf("Hello[%i]\n", i++);
	//pthread_mutex_unlock(&lock);
	return NULL;
}


void	*philo2(void *arg)
{
	//pthread_mutex_lock(&lock);
	int i = 0;
	while (i < 10)
		printf("World[%i]\n", i++);
	//pthread_mutex_unlock(&lock);
	return NULL;
}

void	philo_init(t_philo *philo, char **av)
{
	philo->number_of_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->forks = philo->number_of_philos;


}

int	main(int ac, char **av)
{
	t_philo			philo;
	pthread_t		newthread[atoi(av[1])];
	pthread_mutex_t	fork[atoi(av[1])];

	philo_init(&philo, av);

	//if (ac <= 6)

/*
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
	//pthread_mutex_init(&lock, NULL);
	//number_of_philo = argv[1];
	pthread_create(&newthread[0],NULL, philo, arg);
	pthread_create(&newthread[1],NULL, philo2, arg);

	pthread_join(newthread[0], NULL);
	pthread_join(newthread[1], NULL);
	//pthread_mutex_destroy(&lock);
	return 0;
}
