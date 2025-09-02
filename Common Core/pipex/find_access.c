/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 20:01:16 by pjelinek         ###   ########.fr       */
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

char	*create_full_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	if (!full_path)
		return (free(tmp), NULL);
	free(tmp);
	return (full_path);
}

char	**find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][5], ':'));
		i++;
	}
	return (NULL);
}

void	child_cleanup(t_data *pipex, char *message, unsigned int exit_id)
{
	if (message)
		write(2, message, ft_strlen(message));
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
	exit(exit_id);
}

void	relativ_path_access(t_data *pipex, char *command)
{
	pipex->cmd_split = ft_split(command, ' ');
	if (!pipex->cmd_split)
		return (0);
	if (access(pipex->cmd_split[0], X_OK) == 0)
	{
		if (execve(pipex->cmd_split[0], pipex->cmd_split, pipex->path) == -1)
		{
			free_split(pipex->cmd_split);
			child_cleanup(pipex, "cmd: command not found\n", 126);
		}
	}
	child_cleanup(pipex, "cmd: command not found\n", 127);
}

int	find_access(t_data *pipex, char *command)
{
	int		i;
	char	**path;
	char	*full_path;

	i = 0;
	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
		relativ_path_access(pipex, command);
	path = find_path(pipex->path);
	if (!path)
		return (0);
	pipex->cmd_split = ft_split(command, ' ');
	if (!pipex->cmd_split)
		return (free_split(path), 0);
	while (path[i])
	{
		full_path = create_full_path(path[i], pipex->cmd_split[0]);
		if (!full_path)
			return (free_split(path), free_split(pipex->cmd_split), 0);
		if (access(full_path, X_OK) == 0)
		{
			if (execve(full_path, pipex->cmd_split, pipex->path) == -1)
				return (free_split(path), free_split(pipex->cmd_split), free(full_path), 0);
		}
		else
			free(full_path);
		i++;
	}
	return (free_split(path), free_split(pipex->cmd_split), 0);
}



