/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:18:54 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/09 19:15:57 by pjelinek         ###   ########.fr       */
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
	else
		perror(pipex->cmd_split[0]);
	if (pipex->access_path)
		free_split(pipex->access_path);
	if (pipex->cmd_split)
		free_split(pipex->cmd_split);
	exit(exit_code);
}

void	handle_errno(t_data *pipex, int error_code)
{
	printf("ERROR CODE:%i \n", error_code);
	if (error_code == ISDIR && pipex->cmd_split[0][0] == '/')
		free_split_exit(126, " : Is a directory\n", pipex);
	else if (error_code == ENOENT)
		free_split_exit(127, NULL, pipex);
	else if (error_code == ENOTDIR || error_code == EISDIR
		|| error_code == ENOEXEC || error_code == EACCES)
		free_split_exit(126, NULL, pipex);
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
