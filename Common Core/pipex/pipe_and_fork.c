/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 14:43:07 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_call(char *message)
{
	perror(message);
	exit(1);
}


int	pipe_fork(t_data *pipex)
{
	int		pid;
	int		i;

	if (pipe(pipex->fd.prev) < 0)
		return (1);
	i = 0;
	while (i < pipex->cmd_count)
	{
		if (i != pipex->cmd_count - 1)
			if (pipe(pipex->fd.curr) < 0)
				return (1);
		pid = fork();
		if (pid < 0)
			child_cleanup(pipex, "error fork", 1);
		if (pid == 0)
		{
			if (i == 0)   ///ERSTER DURCHLAUF READ AUS STDIN
			{
				if (dup2(pipex->fd.input, STDIN_FILENO) < 0)
					child_cleanup(pipex, "child - dup2 failed", 1);
			}
			else 		/// AB 2ten DURCHLAUF READ_END in STDIN
			{
				if (dup2(pipex->fd.prev[0], STDIN_FILENO) < 0)
					child_cleanup(pipex, "child - dup2 failed", 1);
			}
			if (close(pipex->fd.input) < 0)
				exit_call("child - close input_fd failed");
			if (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0)
				exit_call("child - close failed");
			if (i == pipex->cmd_count - 1)  // LETZTER DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(pipex->fd.output, STDOUT_FILENO) < 0)
					exit_call("child - dup2 failed");
			}
			else		/// AB ERSTEN DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(pipex->fd.curr[1], STDOUT_FILENO) < 0)
					exit_call("child - dup2 failed");
				if (close(pipex->fd.curr[1]) < 0
					|| close(pipex->fd.curr[0]) < 0)
					child_cleanup(pipex, "child - close failed", 127);
			}
			if (close(pipex->fd.output) < 0)
				exit_call("child - close failed");
			if (!find_access(pipex, pipex->cmds[i]))
				child_cleanup(pipex, "cmd: command not found\n", 127);
		}
		else
		{
			if (i != 0 && (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0))
				return (perror("parent - close failed"), 1);
			if (i != pipex->cmd_count -1 )
			{
				pipex->fd.prev[0] = pipex->fd.curr[0];
				pipex->fd.prev[1] = pipex->fd.curr[1];
			}
		}
		i++;
	}
	if (close(pipex->fd.input) < 0 || close(pipex->fd.output) < 0)
		exit_call("parent - close input_fd failed");
	while (wait(NULL) > 0)
		continue ;
	return (0);
}

int	open_files(int argc, char **argv, char **envp)
{
	t_data	pipex;

	pipex.cmd_count = argc - 3;
	pipex.cmds = &argv[2];
	pipex.path = envp;
	pipex.fd.input = open(argv[1], O_RDONLY);
	if (pipex.fd.input == -1)
		return (1);
	pipex.fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd.output == -1)
		return (1);
	if (pipe_fork(&pipex))
		if (close(pipex.fd.input) < 0 || close(pipex.fd.output) < 0)
			return (1);
	return (0);
}
