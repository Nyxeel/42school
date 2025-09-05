/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_and_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/05 15:46:44 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

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
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][5], ':'));
		i++;
	}
	return (NULL);
}

/* 
static int	path_access(t_data *pipex, char *full_path)
{
   	printf("VOR ACCESS 0");
	
	if (access(full_path, X_OK) == -1) {
        if (errno == EACCES)
            return 126;
   		printf("ACCESS 0");
        return 0;
    }

   printf("Vor EXEC");
   execve(full_path, pipex->cmd_split, pipex->path);
   printf("Nach EXEC");

   
    if (errno == EACCES)
        return 126;
    if (errno == ENOENT || errno == ENOTDIR)
        return 0;
    return 1;
} */

static void	path_access(t_data *pipex, char *full_path)
{
	if (access(full_path, X_OK) == 0)
	{
		execve(full_path, pipex->cmd_split, pipex->path);
		free_split(pipex->cmd_split);
		if (pipex->access_path)
		{
			free_split(pipex->access_path);
			free(full_path);
		}
		cleanup(pipex, "Permission denied\n", 126);
	}
}


/* static void	path_access(t_data *pipex)
{
	pipex->cmd_split = ft_split(command, ' ');
	if (!pipex->cmd_split)
		cleanup(pipex, "command not found\n", 127);
	if (access(pipex->cmd_split[0], X_OK) == 0)
	{
		execve(pipex->cmd_split[0], pipex->cmd_split, pipex->path);
		free_split(pipex->cmd_split);
		if (pipex->access_path)
		{
			free_split(pipex->access_path);
			free(pipex->cmd_split[0]);
		}
		cleanup(pipex, "Permission denied\n", 126);
	}
} */

int	find_access(t_data *pipex, char *command)
{
	int		i;
	char	*path;
	
	pipex->cmd_split = ft_split(command, ' ');
	if (!pipex->cmd_split)
		cleanup(pipex, "command not found\n", 127);
	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
		path_access(pipex, pipex->cmd_split[0]);
	pipex->access_path = find_path(pipex->path);
	if (!pipex->access_path)
		return(free_split(pipex->cmd_split), 0);			
	i = 0;
	while (pipex->access_path[i])
	{
		path = create_full_path(pipex->access_path[i], pipex->cmd_split[0]);
		if (!path)
			return (free_split(pipex->access_path),
		free_split(pipex->cmd_split), 0);
		path_access(pipex, path);
		free(path);
		i++;
	}
	return (free_split(pipex->access_path), free_split(pipex->cmd_split), 0);
}



