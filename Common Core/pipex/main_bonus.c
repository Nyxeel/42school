/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/13 17:42:11 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	pipex;

	if (argc > 3)
	{
		pipex.cmd_count = argc - 3;
		pipex.cmds = &argv[2];
		pipex.path = envp;
		pipex.access_path = NULL;
		pipex.cmd_split = NULL;
		pipex.fd.input = open(argv[1], O_RDONLY);
		if (pipex.fd.input == -1)
			return (perror(argv[1]), 1);
		pipex.fd.output = open(argv[argc - 1], O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
		if (pipex.fd.output == -1)
			return (close(pipex.fd.input), perror(argv[argc - 1]), 1);
		pipe_fork(&pipex);
	}
	else
		write(2, "Enter minimum 3 arguments!\n", 28);
	return (0);
}
