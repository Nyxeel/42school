/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 11:37:45 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_call(char *message)
{
	perror(message);
	exit(1);
}


int	pipe_fork(t_data *pipex, t_fds *fd)
{
	int		pid;
	int		i;

	if (pipe(fd->prev) < 0)
		return (1);
	i = 0;
	while (i < pipex->cmd_count)
	{
		if (i != pipex->cmd_count - 1)
			if (pipe(fd->curr) < 0)
				return (1);
		pid = fork();
		if (pid < 0)
			return (perror("error fork"), 1);
		if (pid == 0)
		{
			if (i == 0)   ///ERSTER DURCHLAUF READ AUS STDIN
			{
				if (dup2(fd->input, STDIN_FILENO) < 0)
					exit_call("child - dup2 failed");
			}
			else 		/// AB 2ten DURCHLAUF READ_END in STDIN
			{
				if (dup2(fd->prev[0], STDIN_FILENO) < 0)
					exit_call("child - dup2 failed");
			}
			if (close(fd->input) < 0)
				exit_call("child - close input_fd failed");
			if (close(fd->prev[0]) < 0 || close(fd->prev[1]) < 0)
				exit_call("child - close failed");
			if (i == pipex->cmd_count - 1)  // LETZTER DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(fd->output, STDOUT_FILENO) < 0)
					exit_call("child - dup2 failed");
			}
			else		/// AB ERSTEN DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(fd->curr[1], STDOUT_FILENO) < 0)
					exit_call("child - dup2 failed");
				if (close(fd->curr[1]) < 0 || close(fd->curr[0]) < 0)
					exit_call("child - close failed");
			}
			if (close(fd->output) < 0)
				exit_call("child - close failed");
			if (!find_access(pipex->path, pipex->cmds[i]))
				exit_call("child - access failed");
		}
		else
		{
			if (i != 0 && (close(fd->prev[0]) < 0 || close(fd->prev[1]) < 0))
				return (perror("parent - close failed"), 1);
			if (i != pipex->cmd_count -1 )
			{
				fd->prev[0] = fd->curr[0];
				fd->prev[1] = fd->curr[1];
			}
		}
		i++;
	}
	if (close(fd->input) < 0 || close(fd->output) < 0)
		exit_call("parent - close input_fd failed");
	while (wait(NULL) > 0)
		continue ;
	return (0);
}

int	open_files(int argc, char **argv, char **envp)
{
	t_fds	fd;
	t_data	pipe;

	pipe.cmd_count = argc - 3;
	pipe.cmds = &argv[2];
	pipe.path = envp;
	fd.input = open(argv[1], O_RDONLY);
	if (fd.input == -1)
		return (1);
	fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd.output == -1)
		return (1);
	if (pipe_fork(&pipe, &fd))
		if (close(fd.input) < 0 || close(fd.output) < 0)
			return (1);
	return (0);
}
