/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/26 14:43:21 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	run_pipex(char **av)
{
	__ENVIROMENT
}


int	main(int ac, char **av)
{
	if (ac == 4)
		run_pipex(av);
	else
		return (1);
	return (0);

}*/


char	**find_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(&envp[i][5], ':');
			if (!path)
				exit(1);
			return (path);
		}
		i++;
	}
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**arr;

	if (argv[1] == "here_doc")
	{
		if (argc >= 6)
			ft_here_doc_bonus();
		else
			ft_perror();
	}
	else
	{
		if (argc >= 5)
			if (pipe_and_fork(argc - 1, &argv[1], find_path(envp)) == 0)
				free_and_exit();
		else
			ft_perror();
	}
	return (0);

/*
	i = 0;
	(void)argc;
	(void)argv;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			arr = ft_split(&envp[i][5], ':');
			i = 0;
			while (arr[i])
			{
				printf("%s\n", arr[i]);
				i++;
			}
		}
		i++;
	} */

}

//(void)(dup2(fd[1], 1) >= 0 && dup2(fd[1], 2) >= 0);
