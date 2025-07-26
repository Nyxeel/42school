/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/26 16:27:36 by pjelinek         ###   ########.fr       */
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

int	start_child1(char *file, char *cmd, char **path, int fd[])
{
	int	old_fd;

	close(fd[0]);
	old_fd = open(file, O_RDONLY);
	if (old_fd == -1)
		return (0);
	dup2(old_fd, stdin);
	dup2(fd[1], stdout);
	close(fd[1]);




}


int	pipe_and_fork(int argc, char **argv, char **path)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		status;

	if (pipe(fd) < 0)
		return (0);
	if (pid1 == fork() <= 0 || pid2 == fork() <= 0)
		return (perror("error fork"), 0);
	else if (pid1 == 0)
		if (!start_child(argv[1], argv[2], path, fd[2]) == 0)
			free_and_exit_child(path);
	else if (pid2 == 0)
		if (!start_child2() == 0)
			return (perror("error child"), 0);
	else if (pid1 > 0)
		if (waitpid(pid1, &status, 0) < 0 || waitpid(pid2, &status, 0) < 0)
			return (perror("waitpid"), 0);
}



