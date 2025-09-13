/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/13 19:05:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close(t_data *pipex)
{
	if (close(pipex->fd.input) < 0)
		cleanup(pipex, "child - close input_fd failed\n", 1);
	if (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0)
		cleanup(pipex, "child - close fd.prev failed\n", 1);
}

static void	parent_process(t_data *pipex, int loop)
{
	if (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0)
		cleanup(pipex, "parent - close fd.prev failed\n", 1);
	if (loop != pipex->cmd_count - 1)
	{
		pipex->fd.prev[0] = pipex->fd.curr[0];
		pipex->fd.prev[1] = pipex->fd.curr[1];
	}
}

static void	child_process(t_data *pipex, int loop)
{
	if (loop == 0)
	{
		if (dup2(pipex->fd.input, STDIN_FILENO) < 0)
			cleanup(pipex, "child - dup2 fd.input failed\n", 1);
	}
	else
		if (dup2(pipex->fd.prev[0], STDIN_FILENO) < 0)
			cleanup(pipex, "child - dup2 fd.prev[0] failed\n", 1);
	ft_close(pipex);
	if (loop == pipex->cmd_count - 1)
	{
		if (dup2(pipex->fd.output, STDOUT_FILENO) < 0)
			cleanup(pipex, "child - dup2 fd.output failed\n", 1);
	}
	else
	{
		if (dup2(pipex->fd.curr[1], STDOUT_FILENO) < 0)
			cleanup(pipex, "child - dup2 fd.curr[1] failed\n", 1);
		if (close(pipex->fd.curr[1]) < 0
			|| close(pipex->fd.curr[0]) < 0)
			cleanup(pipex, "child - close fd.curr failed\n", 1);
	}
	if (close(pipex->fd.output) < 0)
		cleanup(pipex, "child - close fd.output failed\n", 1);
	find_access(pipex, pipex->cmds[loop]);
}

static void	ft_exit_status(pid_t pid)
{
	int		status;
	int		exit_code;
	pid_t	wpid;

	exit_code = 0;
	wpid = wait(&status);
	while (wpid > 0)
	{
		if (wpid == pid)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
		wpid = wait(&status);
	}
	exit(exit_code);
}

void	pipe_fork(t_data *pipex)
{
	int		i;
	pid_t	pid;

	if (pipe(pipex->fd.prev) < 0)
		cleanup(pipex, "open pipe fd.prev failed\n", 1);
	i = 0;
	while (i < pipex->cmd_count)
	{
		if (i != pipex->cmd_count - 1)
			if (pipe(pipex->fd.curr) < 0)
				cleanup(pipex, "pipe fd.curr failed\n", 1);
		pid = fork();
		if (pid < 0)
			cleanup(pipex, "error fork\n", 1);
		if (pid == 0)
			child_process(pipex, i);
		else
			parent_process(pipex, i);
		i++;
	}
	if (close(pipex->fd.input) < 0 || close(pipex->fd.output) < 0)
		cleanup(pipex, "parent - close fd.input/fd.output failed\n", 1);
	ft_exit_status(pid);
}
