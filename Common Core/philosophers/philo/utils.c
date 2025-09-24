/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:52:19 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/24 23:46:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int64_t	gettime(void)
{
	struct timeval	time;
	int64_t			t1;
	int64_t			t2;

	gettimeofday(&time, NULL);
	t1 = (int64_t)(time.tv_sec) * 1000;
	t2 = (time.tv_usec / 1000);
	return (t1 + t2);
}

void	get_starttime(t_data *data)
{
	int		i;
	int64_t	start_time_ms;

	i = 0;
	pthread_mutex_lock(&data->mutex.start_time);
	start_time_ms = gettime();
	while (i < data->number_of_philos)
	{
		data->philo[i].last_meal = start_time_ms;
		i++;
	}
	printf("ZEIT in Jahren: %ld\n", data->philo[0].last_meal / 60 / 60 / 24 / 365 / 1000);
	printf("ZEIT in Tagen: %ld\n", data->philo[0].last_meal / 60 / 60 / 24 /1000);
	printf("ZEIT in MiliSek: %ld\n", data->philo[0].last_meal);
	data->stop = true;
	pthread_mutex_unlock(&data->mutex.start_time);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			total;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (size_t)SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	memset(p, 0, total);
	return (p);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	int			minus;
	long long	num;
	size_t		i;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = minus * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
	}
	if (i > 11)
		return (LLONG_MAX);
	return (minus * num);
}

// +2147483647
