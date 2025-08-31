/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:32:07 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/31 07:53:56 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(void)
{
	unsigned int	number_of_philo;
	pthread_t newthread[number_of_philo];

	//number_of_philo = argv[1];
	pthread_create(&newthread,NULL, philo, arg);



}