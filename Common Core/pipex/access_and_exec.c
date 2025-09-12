/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_and_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/12 15:20:52 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*create_full_path(char *dir, char *cmd)
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

static char	**find_path(char **envp, t_data *pipex)
{
	int	i;

	i = 0;
	if (!envp || !envp[0])
		free_split_exit(127, " : command not found\n", pipex);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][5], ':'));
		i++;
	}
	return (NULL);
}

static void	direct_access(t_data *pipex, char *command)
{
	int	error_code;

	error_code = 0;
	if (access(command, X_OK) == -1)
	{
		error_code = errno;
		handle_errno(pipex, error_code);
	}
	if (execve(command, pipex->cmd_split, pipex->path) == -1)
	{
		error_code = errno;
		handle_errno(pipex, error_code);
	}
}

static void	search_path_access(t_data *pipex, char *full_path)
{
	int	error_code;

	error_code = 0;
	if (access(full_path, X_OK) == 0)
	{
		execve(full_path, pipex->cmd_split, pipex->path);
		error_code = errno;
		free(full_path);
		handle_errno(pipex, error_code);
	}
}

void	find_access(t_data *pipex, char *command)
{
	int		i;
	char	*path;

	pipex->cmd_split = ft_split(command, ' ');
	if (!pipex->cmd_split)
		free_split_exit(1, " : ft_split failed\n", pipex);
	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
		direct_access(pipex, pipex->cmd_split[0]);
	pipex->access_path = find_path(pipex->path, pipex);
	if (!pipex->access_path)
		free_split_exit(1, " : find_path failed\n", pipex);
	i = 0;
	while (pipex->access_path[i])
	{
		path = create_full_path(pipex->access_path[i], pipex->cmd_split[0]);
		if (!path)
			free_split_exit(1, " : create_full_path failed\n", pipex);
		search_path_access(pipex, path);
		free(path);
		i++;
	}
	free_split_exit(127, " : command not found\n", pipex);
}
