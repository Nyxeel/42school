/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/04 15:17:40 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent_process(t_data *pipex, int loop)
{
	if (loop != 0 && (close(pipex->fd.prev[0]) < 0
		|| close(pipex->fd.prev[1]) < 0))
		cleanup(pipex, "parent - close failed", 1);
	if (loop != pipex->cmd_count -1 )
	{
		pipex->fd.prev[0] = pipex->fd.curr[0];
		pipex->fd.prev[1] = pipex->fd.curr[1];
	}
	return (0);
}

int	child_process(t_data *pipex, int loop)
{
	if (loop == 0)   ///ERSTER DURCHLAUF READ AUS STDIN
	{
		if (dup2(pipex->fd.input, STDIN_FILENO) < 0)
			cleanup(pipex, "child - dup2 failed", 1);
	}
	else 		/// AB 2ten DURCHLAUF READ_END in STDIN
	{
		if (dup2(pipex->fd.prev[0], STDIN_FILENO) < 0)
			cleanup(pipex, "child - dup2 failed", 1);
	}
	if (close(pipex->fd.input) < 0)
		cleanup(pipex, "child - close input_fd failed", 1);
	if (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0)
		cleanup(pipex, "child - close failed", 1);
	if (loop == pipex->cmd_count - 1)  // LETZTER DURCHLAUF WRITE_END IN STDOUT
	{
		if (dup2(pipex->fd.output, STDOUT_FILENO) < 0)
			cleanup(pipex, "child - dup2 failed", 1);
	}
	else		/// AB ERSTEN DURCHLAUF WRITE_END IN STDOUT
	{
		if (dup2(pipex->fd.curr[1], STDOUT_FILENO) < 0)
			cleanup(pipex, "child - dup2 failed", 1);
		if (close(pipex->fd.curr[1]) < 0
			|| close(pipex->fd.curr[0]) < 0)
			cleanup(pipex, "child - close failed", 1);
	}
	if (close(pipex->fd.output) < 0)
		cleanup(pipex, "child - close failed", 1);
	if (!find_access(pipex, pipex->cmds[loop]))
	{
		write(2, pipex->cmds[loop], ft_strlen(pipex->cmds[loop]));
		cleanup(pipex, " : command not found ", 127);
	}
	return (0);
}

int	pipe_fork(t_data *pipex)
{
	int		i;
	int		status;
	int		exit_code;
	int		pid;
	pid_t	wpid;

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
			cleanup(pipex, "error fork", 1);
		if (pid == 0)
			exit(child_process(pipex, i));
		else
			parent_process(pipex, i);
		i++;
	}
	if (close(pipex->fd.input) < 0 || close(pipex->fd.output) < 0)
		cleanup(pipex, "parent - close failed", 1);
	while ((wpid = wait(&status)) > 0)
		if (wpid == pid)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
	exit(exit_code);
}

/*
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
			cleanup(pipex, "error fork", 1);
		if (pid == 0)
		{
			if (i == 0)   ///ERSTER DURCHLAUF READ AUS STDIN
			{
				if (dup2(pipex->fd.input, STDIN_FILENO) < 0)
					cleanup(pipex, "child - dup2 failed", 1);
			}
			else 		/// AB 2ten DURCHLAUF READ_END in STDIN
			{
				if (dup2(pipex->fd.prev[0], STDIN_FILENO) < 0)
					cleanup(pipex, "child - dup2 failed", 1);
			}
			if (close(pipex->fd.input) < 0)
				cleanup(pipex, "child - close input_fd failed", 1);
			if (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0)
				cleanup(pipex, "child - close failed", 1);
			if (i == pipex->cmd_count - 1)  // LETZTER DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(pipex->fd.output, STDOUT_FILENO) < 0)
					cleanup(pipex, "child - dup2 failed", 1);
			}
			else		/// AB ERSTEN DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(pipex->fd.curr[1], STDOUT_FILENO) < 0)
					cleanup(pipex, "child - dup2 failed", 1);
				if (close(pipex->fd.curr[1]) < 0
					|| close(pipex->fd.curr[0]) < 0)
					cleanup(pipex, "child - close failed", 127);
			}
			if (close(pipex->fd.output) < 0)
				cleanup(pipex, "child - close failed", 1);
			if (!find_access(pipex, pipex->cmds[i]))
			{
				write(2, pipex->cmds[i], ft_strlen(pipex->cmds[i]));
				cleanup(pipex, " : command not found\n", 127);
			}
		}
		else
		{
			if (i != 0 && (close(pipex->fd.prev[0]) < 0 || close(pipex->fd.prev[1]) < 0))
				cleanup(pipex, "parent - close failed", 1);
			if (i != pipex->cmd_count -1 )
			{
				pipex->fd.prev[0] = pipex->fd.curr[0];
				pipex->fd.prev[1] = pipex->fd.curr[1];
			}
		}
		i++;
	}
	if (close(pipex->fd.input) < 0 || close(pipex->fd.output) < 0)
		cleanup(pipex, "parent - close failed", 1);
	while (wait(pid) > 0)
		continue ;
	return (0);
}
 */

