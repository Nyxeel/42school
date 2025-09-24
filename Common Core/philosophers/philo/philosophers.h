/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:30:05 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/19 17:08:46 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>


typedef struct s_mutex
{
	pthread_mutex_t	wait;
	pthread_mutex_t	count;
	pthread_mutex_t	print;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
}	t_mutex;

typedef struct s_philo
{
	int				last_meal;
	int				id;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
}	t_philo;

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				count;
	t_philo			*philo;
	t_mutex			mutex;
}	t_data;

long long	ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
bool		input_check(char **av);
void		print_lock(char *str, t_philo *data);
void		seperate_philos(t_philo *data);

///    ./philo 5 600 200 200
// TEST RUN: PHILO SHOULD DIE because of computing delay

//valgrind --leak-check=full --show-leak-kinds=all --tool=helgrind

#endif
