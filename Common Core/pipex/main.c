/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/05 14:09:32 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
static int	open_files(int argc, char **argv, char **envp)
{
	t_data	pipex;

	pipex.cmd_count = argc - 3;
	pipex.cmds = &argv[2];
	pipex.path = envp;
	pipex.access_path = NULL;
	pipex.fd.input = open(argv[1], O_RDONLY);
	if (pipex.fd.input == -1)
		return (1);
	pipex.fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd.output == -1)
		return (close(pipex.fd.input));
	pipe_fork(&pipex);
	return (0);
} */

int	main(int argc, char **argv, char **envp)
{
	t_data	pipex;


	//sleep(25);
	if (argc >= 5)
	{
		pipex.cmd_count = argc - 3;
		pipex.cmds = &argv[2];
		pipex.path = envp;
		pipex.access_path = NULL;
		pipex.fd.input = open(argv[1], O_RDONLY);
		if (pipex.fd.input == -1)
			return (1);
		pipex.fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
		if (pipex.fd.output == -1)
			return (close(pipex.fd.input));
		pipe_fork(&pipex);
	}
	else
		perror("Need more argumnets to start program");
	return (0);
}
