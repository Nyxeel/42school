/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/31 12:52:21 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* char	**find_path(char **envp)
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
} */


char	*create_full_path(char *dir, char *cmd)
{
	char *tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (0);
	char *full_path = ft_strjoin(tmp, cmd);
	if (!full_path)
		return (0);
	free(tmp);
	return (full_path);
}




int	main(int argc, char **argv, char **envp)
{
	int i;
	char **arr;
	i = 0;
	(void)argc;
	(void)argv;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			arr = ft_split(&envp[i][5], ':');
			break;
		}
		i++;
	}
	char *befehl = "ls -l";
	char **cmd = ft_split(befehl, ' ');
	i = 0;

	printf("cmd[0]: %s\n", cmd[0]);

	while (arr[i])
	{
		printf("arr[%i]: %s\n", i, arr[i]);
		char *path = create_full_path(arr[i], cmd[0]);
		if (access(path, X_OK) == 0)
			printf("path gefunden!\n");
		else
			free(path);
		i++;
	}




}
