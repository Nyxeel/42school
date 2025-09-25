/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 07:30:05 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/25 15:00:11 by pjelinek         ###   ########.fr       */
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
	bool			wait_ok;
	pthread_mutex_t	print;
	bool			print_ok;
	pthread_mutex_t	print_time;
	bool			print_time_ok;
	pthread_mutex_t	start_time;
	bool			start_time_ok;
	pthread_mutex_t	timestamp;
	bool			timestamp_ok;
	pthread_mutex_t	*fork;
}	t_mutex;

typedef struct s_philo
{
	int64_t		last_meal;
	int			id;
	int			ri_fork;
	int			le_fork;
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int64_t		start_time_ms;
	int64_t		timestamp;
	int64_t		time_to_die;
	int64_t		time_to_eat;
	int64_t		time_to_sleep;
	int			number_of_meals;
	int			number_of_philos;
	int			count;
	bool		stop;
	bool		start;
	pthread_t	monitor;
	t_philo		*philo;
	t_mutex		mutex;
}	t_data;

long		ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
bool		input_check(char **av);
void		print_lock(char *str, t_data *data);
void		seperate_philos(t_data *data);

void	cleanup(t_data *data);
void	mutex_cleanup(pthread_mutex_t *mtx, int i, t_data *data);
void	mutex_destroy(t_data *data);
bool	mutex_init(t_data *data);
void	thread_cleanup(pthread_t *thread, int i);

void	set_forks(t_data *data);
void	set_philo(t_data *data);
bool	start_threads(t_data *data);

void	set_starttime(t_data *data);
int64_t	gettime(void);
void	print_timestamp(t_data *data);



// +2147483647

///    ./philo 5 600 200 200
// TEST RUN: PHILO SHOULD DIE because of computing delay

//valgrind --leak-check=full --show-leak-kinds=all --tool=helgrind

#endif
