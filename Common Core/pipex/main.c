/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 18:39:05 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc >= 6)
			open_files(argc, argv, envp);
		else
			perror("Need more argumnets to start program");
	}
	else
	{
		if (argc >= 5)
			open_files(argc, argv, envp);
		else
			perror("Need more argumnets to start program");
	}
	return (0);
}
