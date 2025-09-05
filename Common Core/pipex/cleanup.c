/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:18:54 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/05 15:19:41 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
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

void	cleanup(t_data *pipex, char *message, int exit_code)
{
	if (message && exit_code == 127)
		perror(message);
	if (pipex->fd.input >= 0)
		close(pipex->fd.input);
	if (pipex->fd.output >= 0)
		close(pipex->fd.output);
	if (pipex->fd.prev[0] >= 0)
		close(pipex->fd.prev[0]);
	if (pipex->fd.prev[1] >= 0)
		close(pipex->fd.prev[1]);
	if (pipex->fd.curr[0] >= 0)
		close(pipex->fd.curr[0]);
	if (pipex->fd.curr[1] >= 0)
		close(pipex->fd.curr[1]);
	pipex->status = exit_code;
	exit(exit_code);
}
