/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2pipe_and_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/02 12:13:21 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_exit_child(char **path)
{
	int	count;

	count = 0;
	perror("error child");
	if (path || *path)
	{
		while (path[count] != NULL)
			count++;
		ft_freeall(&path, count);
	}
	exit(1);
}

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
	char *tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (0);
	char *full_path = ft_strjoin(tmp, cmd);
	if (!full_path)
		return (0);
	free(tmp);
	return (full_path);
}

int	find_access(char **envp, char *command)
{
	int		i;
	char	**arr;
	char	**cmd;

	cmd = ft_split(command, ' ');
	if (!cmd)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			arr = ft_split(&envp[i][5], ':');
			if (!arr)
				return (free_split(cmd), 0);
			break ;
		}
		i++;
	}
	i = 0;
	while (arr[i])
	{
		printf("arr[%i]: %s\n", i, arr[i]);
		char *path = create_full_path(arr[i], cmd[0]);
		if (access(path, X_OK) == 0)
			if (execve(path, cmd, envp) == -1)
				return (free_split(arr), free_split(cmd), 0); ///////////////////////
		else
			free(path);
		i++;
	}
	return (free_split(arr), free_split(cmd), 0);
}


int	start_child1(char *file, char *cmd, char **path, int fd[])
{
	int	old_fd;

	old_fd = open(file, O_RDONLY);
	if (old_fd == -1)
		return (1);
	if (dup2(old_fd, stdin) < 0 || dup2(fd[1], stdout) < 0)
		return (perror("child - dup2 failed"), 1);
	if (close(fd[1]) < 0 || close(fd[0]) < 0 || close(old_fd) < 0)
		return (perror("child - close failed"), 1);
	if (!find_access(path, cmd))
		return (perror("child - access failed"), 1);
	return (0);
}


int	pipe_and_fork(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		status;

	if (pipe(fd) < 0)
		return (1);
	if (pid1 == fork() != 0)
		return (perror("error fork"), 1);
	else if (pid1 == 0)
	{
		pid1 = start_child(argv[1], argv[2], envp, fd[2]);
		exit(pid1);
	}
	else if (pid1 > 0)
		if (waitpid(pid1, &status, 0) < 0)
			return (perror("waitpid"), 1);
}



