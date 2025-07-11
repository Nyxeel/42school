/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/11 21:16:18 by pjelinek         ###   ########.fr       */
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

} */

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**arr;

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
	}
	return (0);
}

//(void)(dup2(fd[1], 1) >= 0 && dup2(fd[1], 2) >= 0);
