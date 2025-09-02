/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 11:49:04 by netrunner        ###   ########.fr       */
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
		return (NULL);
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

/* void	child_cleanup(t_data *pipex, t_fds *fd)
{
	if (fd->input >= 0)
    	close(fd->input);
	if (fd->output >= 0)
    	close(fd->output);
	if (fd->prev[0] >= 0)
    	close(fd->prev[0]);
	if (fd->prev[1] >= 0)
    	close(fd->prev[1]);
	if (fd->curr[0] >= 0)
    	close(fd->curr[0]);
	if (fd->curr[1] >= 0)
    	close(fd->curr[1]);
} */

int	find_access(char **envp, char *command)
{
	int		i;
	char	**path;
	char	**cmd;
	char	*full_path;

	i = 0;
	path = find_path(envp);
	if (!path)
		return (0);
	while (path[i])
		printf("%s", path[i++]);
	cmd = ft_split(command, ' ');
	if (!cmd)
		return (free_split(path), 0);
	i = 0;
	while (path[i])
	{
		full_path = create_full_path(path[i], cmd[0]);
		if (!full_path)
			return (free_split(path), free_split(cmd), 0);
		if (access(full_path, X_OK) == 0)
		{
			if (execve(full_path, cmd, envp) == -1)
				return (free_split(path), free_split(cmd), free(full_path), 0);
		}
		else
			free(full_path);
		i++;
	}
	return (free_split(path), free_split(cmd), free(full_path), 0);
}



