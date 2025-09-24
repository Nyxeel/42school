/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:05:45 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/25 00:49:45 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void	free_split(char **split)
{
	int	count;

	count = 0;
	if (split || *split)
	{
		while (split[count] != NULL)
			count++;
		ft_freeall(split, count);
	}
}

void	free_split_exit(int exit_code, char *message, t_data *pipex)
{
	if (message)
	{
		if (pipex->cmd_split)
			write(2, pipex->cmd_split[0], ft_strlen(pipex->cmd_split[0]));
		write(2, message, ft_strlen(message));
	}
	else
		perror(pipex->cmd_split[0]);
	if (pipex->access_path)
		free_split(pipex->access_path);
	if (pipex->cmd_split)
		free_split(pipex->cmd_split);
	exit(exit_code);
} */

void	thread_cleanup(pthread_t *thread, int i)
{
	int	start;

	start = 0;
	while (start < i)
		pthread_join(thread[start++], NULL);
}

void	mutex_cleanup(pthread_mutex_t *mtx, int i, t_data *data)
{
	int	start;

	start = 0;
	while (start < i)
		pthread_mutex_destroy(&mtx[start++]);
	if (data->mutex.wait_ok == true)
		pthread_mutex_destroy(&data->mutex.wait);
	if (data->mutex.print_ok == true)
		pthread_mutex_destroy(&data->mutex.print);
	if (data->mutex.start_time_ok == true)
		pthread_mutex_destroy(&data->mutex.start_time);
	if (data->mutex.timestamp_ok == true)
		pthread_mutex_destroy(&data->mutex.timestamp);
}


void	cleanup(t_data *data)
{
	if (data->mutex.fork)
		free(data->mutex.fork);
	if (data->philo)
		free(data->philo);
}
