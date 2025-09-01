/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/01 17:48:39 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_call(char *message)
{
	perror(message);
	exit(1);
}


int	pipe_fork(int cmd_count, char **cmds, char **path, int input_fd, int output_fd)
{
	int		curr_fd[2];
	int		prev_fd[2];
	int		pid;
	int		i;

	if (pipe(prev_fd) < 0)
		return (1);
	i = 0;
	while (i < cmd_count)
	{
		if (i != cmd_count - 1)
			if (pipe(curr_fd) < 0)
				return (1);
		pid = fork();
		if (pid < 0)
			return (perror("error fork"), 1);
		if (pid == 0)
		{
			if (i == 0)   ///ERSTER DURCHLAUF READ AUS STDIN
			{
				if (dup2(input_fd, STDIN_FILENO) < 0)
					exit_call("child - dup2 failed");
				if (close(input_fd) < 0)
					exit_call("child - close input_fd failed");
			}
			else 		/// AB 2ten DURCHLAUF READ_END in STDIN
			{
				if (dup2(prev_fd[0], STDIN_FILENO) < 0)
					exit_call("child - dup2 failed");
				if (close(prev_fd[0]) < 0 || close(prev_fd[1]) < 0)
					exit_call("child - close failed");
			}
			if (i == cmd_count - 1)  // LETZTER DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(output_fd, STDOUT_FILENO) < 0)
					exit_call("child - dup2 failed");
				if (close(output_fd) < 0)
					exit_call("child - close failed");
			}
			else		/// AB ERSTEN DURCHLAUF WRITE_END IN STDOUT
			{
				if (dup2(curr_fd[1], STDOUT_FILENO) < 0)
					exit_call("child - dup2 failed");
				if (close(curr_fd[1]) < 0 || close(curr_fd[0]) < 0)
					exit_call("child - close failed");
			}
			if (!find_access(path, cmds[i]))
				exit_call("child - access failed");
		}
		else
		{
			if (i != 0 && (close(prev_fd[0]) < 0 || close(prev_fd[1]) < 0))
				return (perror("parent - close failed"), 1);
			prev_fd[0] = curr_fd[0];
			prev_fd[1] = curr_fd[1];
		}
		i++;
	}
	while (wait(NULL) > 0)
		continue ;
	exit(0);
}

int	open_files(int argc, char **argv, char **envp)
{
	int	input_fd;
	int	output_fd;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		return (1);
	output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		return (1);
	if (pipe_fork(argc - 3, &argv[2], envp, input_fd, output_fd))
		if (close(input_fd) < 0 || close(output_fd) < 0)
			return (1);
	return (0);
}

int	open_files_bonus(int argc, char **argv, char **envp)
{
	int	input_fd;
	int	output_fd;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		return (1);
	output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (output_fd == -1)
		return (1);
	if (pipe_fork(argc - 3, &argv[2], envp, input_fd, output_fd))
		if (close(input_fd) < 0 || close(output_fd) < 0)
			return (1);
	return (0);
}
