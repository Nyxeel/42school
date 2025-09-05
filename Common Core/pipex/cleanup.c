/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:18:54 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/05 18:46:04 by pjelinek         ###   ########.fr       */
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
void	free_split_exit(int exit_code, char *message, t_data *pipex)
{
	if (message)
	{
		write(2, pipex->cmd_split[0], ft_strlen(pipex->cmd_split[0]));
		write(2, message, ft_strlen(message));
	}
	if (pipex->access_path)
		free_split(pipex->access_path);
	if (pipex->cmd_split)
		free_split(pipex->cmd_split);
	exit(exit_code);
}


void	cleanup(t_data *pipex, char *message, int exit_code)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (pipex->path)
		free_split(pipex->access_path);
	if (pipex->cmd_split)
		free_split(pipex->cmd_split);
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
